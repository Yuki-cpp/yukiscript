#include "generators.hpp"

#include <iostream>

#include "op_generators.hpp"
#include "var_generators.hpp"
#include "control_generators.hpp"
#include "function_generators.hpp"

#include "utils/token_utils.hpp"


std::unique_ptr<yuki::statements::evaluable_stmt> yuki::generators::generate_evaluable_stmt(const std::string& root_token)
{
	auto tokens = yuki::utils::separate_tokens(root_token);

	if(tokens.size() == 3 && yuki::utils::is_binary_operator(tokens[0]))
	{
		return generate_binary_op_stmt(tokens);
	}
	else if(tokens.size() == 2 && yuki::utils::is_unary_operator(tokens[0]))
	{
		return generate_unary_op_stmt(tokens);
	}
	else if(tokens.size() == 1 && yuki::utils::is_literal(tokens[0]))
	{
		return generate_literal_stmt(tokens);
	}
	else if(tokens.size() == 1 && yuki::utils::is_user_defined(tokens[0]))
	{
		return generate_get_var(tokens);
	}
	else if(tokens.size() == 2 && yuki::utils::is_user_defined(tokens[0]))
	{
		return generate_call_function(tokens);
	}
	
	std::cout << root_token << std::endl;
	return nullptr;
}



std::unique_ptr<yuki::statements::executable_stmt> yuki::generators::generate_executable_stmt(const std::string& root_token)
{
	auto tokens = yuki::utils::separate_tokens(root_token);

	if(tokens.size() > 0 && tokens[0][0] == '(')
	{
		return generate_compound_stmt(tokens);
	}
	else if(tokens.size() == 2 && tokens[0] == "print")
	{
		return generate_print_stmt(tokens);
	}
	else if(tokens.size() == 2 && tokens[0] == "var")
	{
		return generate_def_var_stmt(tokens);
	}
	else if(tokens.size() == 3 && tokens[0] == "set" && yuki::utils::is_user_defined(tokens[1]))
	{
		return generate_set_stmt(tokens);
	}
	else if(tokens.size() == 3 && tokens[0] == "while")
	{
		return generate_while_stmt(tokens);
	}
	else if((tokens.size() == 3 || tokens.size() == 4) && tokens[0] == "if")
	{
		return generate_if_stmt(tokens);
	}
	else if(tokens.size() == 4 && tokens[0] == "function" && yuki::utils::is_user_defined(tokens[1]))
	{
		return generate_def_function(tokens);
	}
	else
	{
		return generate_evaluable_stmt(root_token);
	}
}


std::unique_ptr<yuki::statements::compound_stmt> yuki::generators::generate_compound_stmt(const std::vector<std::string>& tokens)
{
	std::vector<std::unique_ptr<yuki::statements::executable_stmt>> stmts;
	for(const auto & s : tokens)
	{
		auto stmt = generate_executable_stmt(s);
		if(stmt)
		{
			stmts.push_back(std::move(stmt));
		}
		else
		{
			return nullptr;
		}
	}

	return std::make_unique<yuki::statements::compound_stmt>(std::move(stmts));
}
