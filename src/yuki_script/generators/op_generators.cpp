#include "op_generators.hpp"

#include <cassert>

#include "generators.hpp"
#include "utils/token_utils.hpp"

#include "statements/binary_op_stmts.hpp"
#include "statements/unary_op_stmts.hpp"

std::unique_ptr<yuki::statements::evaluable_stmt> yuki::generators::generate_binary_op_stmt(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 3);
	assert(yuki::utils::is_binary_operator(tokens[0]));

	std::unique_ptr<yuki::statements::evaluable_stmt> lhs = generate_evaluable_stmt(tokens[1]);

	if(std::unique_ptr<yuki::statements::evaluable_stmt> rhs = generate_evaluable_stmt(tokens[2]); 
	lhs && rhs)
	{
		if(tokens[0] == "&&")
			return std::make_unique<yuki::statements::and_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == "||")
			return std::make_unique<yuki::statements::or_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == "<")
			return std::make_unique<yuki::statements::l_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == "<=")
			return std::make_unique<yuki::statements::leq_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == ">")
			return std::make_unique<yuki::statements::g_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == ">=")
			return std::make_unique<yuki::statements::geq_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == "==")
			return std::make_unique<yuki::statements::eq_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == "!=")
			return std::make_unique<yuki::statements::neq_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == "+")
			return std::make_unique<yuki::statements::addition_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == "-")
			return std::make_unique<yuki::statements::substraction_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == "*")
			return std::make_unique<yuki::statements::multiplication_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == "/")
			return std::make_unique<yuki::statements::division_stmt>(std::move(lhs), std::move(rhs));
		if(tokens[0] == "%")
			return std::make_unique<yuki::statements::modulo_stmt>(std::move(lhs), std::move(rhs));

	}
	return nullptr;
}



std::unique_ptr<yuki::statements::evaluable_stmt> yuki::generators::generate_unary_op_stmt(const std::vector<std::string>& tokens)
{
	assert(tokens.size() == 2);
	assert(yuki::utils::is_unary_operator(tokens[0]));

	if(std::unique_ptr<yuki::statements::evaluable_stmt> val = generate_evaluable_stmt(tokens[1]))
	{
		if(tokens[0] == "-")
			return std::make_unique<yuki::statements::unary_neg_stmt>(std::move(val));
		if(tokens[0] == "!")
			return std::make_unique<yuki::statements::unary_not_stmt>(std::move(val));
	}
	return nullptr;
}

