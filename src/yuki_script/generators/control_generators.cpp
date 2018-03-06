#include "control_generators.hpp"

#include <cassert>

#include "generators.hpp"
#include "token_utils.hpp"

std::unique_ptr<yuki::statements::while_stmt> yuki::generators::generate_while_stmt(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 3);
	assert(tokens[0] == "while");

	auto condition = generate_evaluable_stmt(tokens[1]);
	if(!condition)
	{
		return nullptr;
	}

	const auto toks = yuki::script::utils::separate_tokens(tokens[2]);
	auto body = generate_compound_stmt(toks);
	if(!body)
	{
		return nullptr;
	}

	return std::make_unique<yuki::statements::while_stmt>(std::move(condition), std::move(body));
}


std::unique_ptr<yuki::statements::if_stmt> yuki::generators::generate_if_stmt(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 3);
	assert(tokens[0] == "if");

	auto condition = generate_evaluable_stmt(tokens[1]);
	if(!condition)
	{
		return nullptr;
	}

	const auto toks = yuki::script::utils::separate_tokens(tokens[2]);
	auto body = generate_compound_stmt(toks);
	if(!body)
	{
		return nullptr;
	}

	return std::make_unique<yuki::statements::if_stmt>(std::move(condition), std::move(body));
}
