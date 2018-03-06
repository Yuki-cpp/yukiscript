#ifndef YUKI_SCRIPT_STMTS_BINARY_OP_GENERATORS_HPP
#define YUKI_SCRIPT_STMTS_BINARY_OP_GENERATORS_HPP

#include <vector>
#include <string>
#include <memory>

#include "stmts.hpp"

namespace yuki::generators
{

std::unique_ptr<yuki::statements::evaluable_stmt> generate_binary_op_stmt(const std::vector<std::string> & tokens);

std::unique_ptr<yuki::statements::evaluable_stmt> generate_unary_op_stmt(const std::vector<std::string> & tokens);


}







#endif
