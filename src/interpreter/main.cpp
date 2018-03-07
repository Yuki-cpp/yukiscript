#include <iostream>
#include <fstream>
#include <string>

#include "context/context_stack.hpp"
#include "generators/generators.hpp"
#include "utils/utils.hpp"

void parse(std::ostream & os , const std::string & code)
{
	std::string processed_code = code;
	yuki::utils::process_whitespaces(processed_code);

	yuki::context::context_stack stack;
	auto ast = yuki::generators::generate_executable_stmt(processed_code);

	if(ast)
	{
		ast->execute(stack);
	}
	else
	{
		os << "Terminated without executing..." << std::endl;
	}
}


int main(int argc, char** argv)
{
	if(argc >= 2)
	{
		std::ifstream t(argv[1]);
		std::string code((std::istreambuf_iterator<char>(t)),
		                 std::istreambuf_iterator<char>());

		if(argc >= 3 && std::string("debug") == argv[2])
		{
			yuki::utils::print_tree(code, std::cout);
		}
		else
		{
			parse(std::cout, code);
		}
	}
}
