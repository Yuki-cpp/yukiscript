#ifndef YUKI_SCRIPT_PARSING_UTILS_HPP
#define YUKI_SCRIPT_PARSING_UTILS_HPP


#include <string>
#include <iosfwd>

namespace yuki::utils
{


void process_whitespaces(std::string & code);

void print_tree(const std::string & code, std::ostream & os);


}




#endif
