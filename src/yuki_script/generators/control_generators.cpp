#include "control_generators.hpp"

#include <cassert>

#include "generators.hpp"
#include "utils/token_utils.hpp"

std::unique_ptr<yuki::statements::while_stmt> yuki::generators::generate_while_stmt(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 3);
	assert(tokens[0] == "while");

	auto condition = generate_evaluable_stmt(tokens[1]);
	if(!condition)
	{
		return nullptr;
	}

	const auto toks = yuki::utils::separate_tokens(tokens[2]);
	auto body = generate_compound_stmt(toks);
	if(!body)
	{
		return nullptr;
	}

	return std::make_unique<yuki::statements::while_stmt>(std::move(condition), std::move(body));
}


std::unique_ptr<yuki::statements::if_stmt> yuki::generators::generate_if_stmt(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 3 || tokens.size() == 4);
	assert(tokens[0] == "if");

	auto condition = generate_evaluable_stmt(tokens[1]);
	if(!condition)
	{
		return nullptr;
	}

	const auto toks = yuki::utils::separate_tokens(tokens[2]);
	auto body = generate_compound_stmt(toks);
	if(!body)
	{
		return nullptr;
	}

	std::unique_ptr<yuki::statements::compound_stmt> else_body = nullptr;
	if(tokens.size() == 4)
	{
		const auto else_toks = yuki::utils::separate_tokens(tokens[3]);
		else_body = generate_compound_stmt(else_toks);
		if(!else_body)
		{
			return nullptr;
		}
	}

	return std::make_unique<yuki::statements::if_stmt>(std::move(condition), std::move(body), std::move(else_body));
}
