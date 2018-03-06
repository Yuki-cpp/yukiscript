#include "function_generators.hpp"

#include <cassert>

#include "generators.hpp"
#include "utils/token_utils.hpp"

std::unique_ptr<yuki::statements::def_function_stmt> yuki::generators::generate_def_function(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 4);
	assert(tokens[0] == "function");
	assert(yuki::utils::is_user_defined(tokens[1]));

	auto arguments = yuki::utils::separate_tokens(tokens[2]);
	for(const auto & arg : arguments)
	{
		if(!yuki::utils::is_user_defined(arg))
		{
			return nullptr;
		}
	}

	const auto toks = yuki::utils::separate_tokens(tokens[3]);
	auto body = generate_compound_stmt(toks);
	if(!body)
	{
		return nullptr;
	}

	return std::make_unique<yuki::statements::def_function_stmt>(tokens[1], std::move(arguments), std::move(body));
}



std::unique_ptr<yuki::statements::call_function_stmt> yuki::generators::generate_call_function(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 2);
	assert(yuki::utils::is_user_defined(tokens[0]));

	std::vector<yuki::statements::function_arg_t> arguments;
	const auto toks = yuki::utils::separate_tokens(tokens[1]);
	for(const auto & token : toks)
	{
		if(yuki::utils::is_user_defined(token))
		{
			arguments.push_back(token);
		}
		else
		{
			auto eval = generate_evaluable_stmt(token);
			if(!eval)
			{
				return nullptr;
			}
			arguments.push_back(std::move(eval));
		}
	}


	return std::make_unique<yuki::statements::call_function_stmt>(tokens[0], std::move(arguments));
}
