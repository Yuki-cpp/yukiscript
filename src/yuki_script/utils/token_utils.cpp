#include "token_utils.hpp"

#include <cassert>
#include <sstream>
#include <algorithm>

#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string.hpp>

bool  yuki::utils::is_single_statement(const std::string& code)
{
	assert(code != "");

	if(code[0] != '(' || code[code.size() - 1] != ')')
	{
		return false;
	}

	std::size_t depth = 0;

	for(auto i = 0u; i < code.size() - 1 ; ++i)
	{
		if(code[i] == '(')
		{
			depth++;
		}
		else if(code[i] == ')')
		{
			depth--;
		}

		if(depth == 0)
		{
			return false;
		}
	}

	return true;
}


std::vector<std::string> yuki::utils::separate_tokens(std::string code)
{
	if(is_single_statement(code))
	{
		boost::trim_left_if(code, [](char c)
		{
			return c == ' ';
		});
		boost::trim_right_if(code, [](char c)
		{
			return c == ' ';
		});

		code = std::string(code.begin() + 1, code.begin() + code.size() - 1);
	}



	std::vector<std::string> tokens;
	std::string current_token = "";
	std::size_t depth = 0;

	for(auto c : code)
	{
		if(c == ' ' && depth == 0)
		{
			if(current_token != "")
			{
				tokens.push_back(current_token);
			}
			current_token = "";
			continue;
		}
		current_token += c;

		if(c == '(')
		{
			depth++;
		}

		if(c == ')')
		{
			depth--;
			if(depth == 0)
			{
				if(current_token != "")
				{
					tokens.push_back(current_token);
				}
				current_token = "";
				continue;
			}
		}
	}

	if(current_token != "")
	{
		tokens.push_back(current_token);
	}

	return tokens;
}


bool yuki::utils::is_keyword(const std::string& id)
{
	static std::vector<std::string> keywords {"var", "function", "set", "print", "while", "if"};
	return std::find(keywords.begin(), keywords.end(), id) != keywords.end();
}

bool yuki::utils::is_binary_operator(const std::string& id)
{
	static std::vector<std::string> operators {"&&", "||", "+", "-", "/", "*", "<", "<=", ">" , ">=" , "==", "!=", "%"};
	return std::find(operators.begin(), operators.end(), id) != operators.end();
}

bool yuki::utils::is_unary_operator(const std::string& id)
{
	static std::vector<std::string> operators {"-", "!"};
	return std::find(operators.begin(), operators.end(), id) != operators.end();
}

bool yuki::utils::is_operator(const std::string& id)
{
	return is_unary_operator(id) || is_binary_operator(id);
}

bool yuki::utils::is_bool_literal(const std::string& id)
{
	return id == "true" || id == "false";
}

bool yuki::utils::is_int_literal(const std::string& id)
{
	std::istringstream iss(id);
	int f;
	iss >> std::noskipws >> f;
	return iss.eof() && !iss.fail();
}

bool yuki::utils::is_double_literal(const std::string& id)
{
	if(is_int_literal(id))
	{
		return false;
	}

	std::istringstream iss(id);
	double f;
	iss >> std::noskipws >> f;
	return iss.eof() && !iss.fail();
}

bool yuki::utils::is_literal(const std::string& id)
{
	return is_double_literal(id) ||
	       is_int_literal(id) ||
	       is_bool_literal(id) ||
	       is_char_literal(id) ||
	       is_string_literal(id);
}

bool yuki::utils::is_user_defined(const std::string& id)
{
	return id != "" &&
	       (id[0] >= 'a' && id[0] <= 'z') &&
	       !is_literal(id) &&
	       !is_operator(id) &&
	       !is_keyword(id);
}


bool yuki::utils::is_string_literal(const std::string& id)
{
	return id.size() >= 2 && id[0] == '"' && id[id.size() - 1] == '"';
}

bool yuki::utils::is_char_literal(const std::string& id)
{
	bool ret = id.size() > 2;
	ret = ret && id.size() <= 4;
	ret = ret && id[0] == '\'' && id[id.size() - 1] == '\'';

	if(id.size() == 4)
	{
		ret = ret && id[1] == '\\';
	}
	return ret;
}


void yuki::utils::replace_special_char(std::string & str)
{
	boost::replace_all(str, "\\n", "\n");
	boost::replace_all(str, "\\t", "\t");
	boost::replace_all(str, "\\a", "\a");
}

char yuki::utils::as_char(const std::string& id)
{
	assert(is_char_literal(id));
	auto tmp = id;
	replace_special_char(tmp);
	return tmp[1];
}




