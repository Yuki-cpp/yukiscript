#ifndef YUKI_SCRIPT_STMTS_VAR_GENERATORS_HPP
#define YUKI_SCRIPT_STMTS_VAR_GENERATORS_HPP

#include <memory>
#include <string>

#include "var_stmts.hpp"
#include "stmts.hpp"

namespace yuki::generators
{
	
std::unique_ptr<yuki::statements::get_var_stmt> generate_get_var(const std::vector<std::string> & tokens);

std::unique_ptr<yuki::statements::literal_stmt> generate_literal_stmt(const std::vector<std::string> & tokens);

std::unique_ptr<yuki::statements::print_stmt> generate_print_stmt(const std::vector<std::string> & tokens);

std::unique_ptr<yuki::statements::def_var_stmt> generate_def_var_stmt(const std::vector<std::string> & tokens);

std::unique_ptr<yuki::statements::set_stmt> generate_set_stmt(const std::vector<std::string> & tokens);


}





#endif
