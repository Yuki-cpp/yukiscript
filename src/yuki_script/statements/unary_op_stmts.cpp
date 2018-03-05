#include "unary_op_stmts.hpp"


yuki::statements::unary_neg_stmt::unary_neg_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && value):
	unary_op_stmt<unary_op_callback>(std::move(value), [](const yuki::type::variable & v)
{
	return -v;
})
{}

yuki::statements::unary_not_stmt::unary_not_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && value):
	unary_op_stmt<unary_op_callback>(std::move(value), [](const yuki::type::variable & v)
{
	return !v;
})
{}
