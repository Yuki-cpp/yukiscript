#ifndef YUKI_SCRIPT_STMTS_GENERATORS_HPP
#define YUKI_SCRIPT_STMTS_GENERATORS_HPP

#include <memory>
#include <string>
#include <vector>

#include "stmts.hpp"

namespace yuki::generators
{
std::unique_ptr<yuki::statements::executable_stmt> generate_executable_stmt(const std::string & root_token);

std::unique_ptr<yuki::statements::evaluable_stmt> generate_evaluable_stmt(const std::string &  root_token);

std::unique_ptr<yuki::statements::compound_stmt> generate_compound_stmt(const std::vector<std::string> & tokens);

}





#endif
