#ifndef YUKI_SCRIPT_STMTS_CONTROL_GENERATORS_HPP
#define YUKI_SCRIPT_STMTS_CONTROL_GENERATORS_HPP

#include <string>
#include <vector>
#include <memory>


#include "control_stmts.hpp"


namespace yuki::generators
{

std::unique_ptr<yuki::statements::while_stmt> generate_while_stmt(const std::vector<std::string> & tokens);

std::unique_ptr<yuki::statements::if_stmt> generate_if_stmt(const std::vector<std::string> & tokens);


}



#endif
