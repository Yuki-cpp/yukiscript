#include "var_generators.hpp"

#include <cassert>
#include <iostream>
#include "utils/token_utils.hpp"
#include "generators.hpp"

#include <boost/algorithm/string.hpp>

std::unique_ptr<yuki::statements::get_var_stmt> yuki::generators::generate_get_var(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 1);
	assert(yuki::utils::is_user_defined(tokens[0]));
	return std::make_unique<yuki::statements::get_var_stmt>(tokens[0]);
}



std::unique_ptr<yuki::statements::literal_stmt> yuki::generators::generate_literal_stmt(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 1);
	assert(yuki::utils::is_literal(tokens[0]));

	yuki::type::variable var;

	if(yuki::utils::is_int_literal(tokens[0]))
	{
		var = yuki::type::variable(std::atoi(tokens[0].c_str()));
	}
	else if(yuki::utils::is_double_literal(tokens[0]))
	{
		var = yuki::type::variable(std::atof(tokens[0].c_str()));
	}
	else if(yuki::utils::is_bool_literal(tokens[0]))
	{
		var = tokens[0] == "true" ? yuki::type::variable(true) : yuki::type::variable(false);
	}
	else if(yuki::utils::is_char_literal(tokens[0]))
	{
		var = yuki::type::variable(yuki::utils::as_char(tokens[0]));
	}
	else if(yuki::utils::is_string_literal(tokens[0]))
	{
		std::string tmp = tokens[0];
		yuki::utils::replace_special_char(tmp);
		boost::trim_if(tmp, [](char c)
		{
			return c == '"';
		});
		var = yuki::type::variable(tmp);
	}
	else
	{
		return nullptr;
	}

	return std::make_unique<yuki::statements::literal_stmt>(var);
}

std::unique_ptr<yuki::statements::print_stmt> yuki::generators::generate_print_stmt(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 2);
	assert(tokens[0] == "print");

	return std::make_unique<yuki::statements::print_stmt>(generate_evaluable_stmt(tokens[1]));
}

std::unique_ptr<yuki::statements::def_var_stmt> yuki::generators::generate_def_var_stmt(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 2);
	assert(tokens[0] == "var");
	assert(yuki::utils::is_user_defined(tokens[1]));

	return std::make_unique<yuki::statements::def_var_stmt>(tokens[1]);
}

std::unique_ptr<yuki::statements::set_stmt> yuki::generators::generate_set_stmt(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 3);
	assert(tokens[0] == "set");
	assert(yuki::utils::is_user_defined(tokens[1]));

	auto s = generate_evaluable_stmt(tokens[2]);
	if(!s)
	{
		return nullptr;
	}

	return std::make_unique<yuki::statements::set_stmt>(tokens[1], std::move(s));
}









