#ifndef YUKI_SCRIPT_STMTS_TOKEN_UTILS_HPP
#define YUKI_SCRIPT_STMTS_TOKEN_UTILS_HPP

#include <string>
#include <vector>


namespace yuki::utils
{

bool is_single_statement(const std::string & code);

std::vector<std::string> separate_tokens(std::string code);

bool is_keyword(const std::string & id);

bool is_binary_operator(const std::string & id);

bool is_unary_operator(const std::string & id);

bool is_operator(const std::string & id);

bool is_bool_literal(const std::string &id);

bool is_int_literal(const std::string & id);

bool is_double_literal(const std::string & id);

bool is_literal(const std::string & id);

bool is_user_defined(const std::string & id);

bool is_string_literal(const std::string & id);

bool is_char_literal(const std::string & id);

void replace_special_char(std::string & str);

char as_char(const std::string & id);

}


#endif
