#include "binary_op_stmts.hpp"


yuki::statements::or_stmt::or_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var || rhs_var;
})
{}

yuki::statements::and_stmt::and_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var && rhs_var;
})
{}


yuki::statements::l_stmt::l_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var < rhs_var;
})
{}

yuki::statements::leq_stmt::leq_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var <= rhs_var;
})
{}

yuki::statements::g_stmt::g_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var > rhs_var;
})
{}

yuki::statements::geq_stmt::geq_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var >= rhs_var;
})
{}

yuki::statements::eq_stmt::eq_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var == rhs_var;
})
{}

yuki::statements::neq_stmt::neq_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var != rhs_var;
})
{}

yuki::statements::addition_stmt::addition_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var + rhs_var;
})
{}

yuki::statements::substraction_stmt::substraction_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var - rhs_var;
})
{}

yuki::statements::multiplication_stmt::multiplication_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var * rhs_var;
})
{}

yuki::statements::division_stmt::division_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var / rhs_var;
})
{}

yuki::statements::modulo_stmt::modulo_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs):
	binary_op_stmt<binary_op_callback>(std::move(lhs), std::move(rhs), [](const yuki::type::variable & lhs_var, const yuki::type::variable & rhs_var)
{
	return lhs_var % rhs_var;
})
{}



