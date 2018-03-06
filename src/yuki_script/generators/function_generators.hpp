#ifndef YUKI_SCRIPT_STMTS_FUNCTION_GENERATORS_HPP
#define YUKI_SCRIPT_STMTS_FUNCTION_GENERATORS_HPP

#include <memory>
#include <string>

#include "function_stmts.hpp"
#include "stmts.hpp"

namespace yuki::generators
{
	std::unique_ptr<yuki::statements::call_function_stmt> generate_call_function(const std::vector<std::string> & tokens);
	
	std::unique_ptr<yuki::statements::def_function_stmt> generate_def_function(const std::vector<std::string> & tokens);
}



#endif
