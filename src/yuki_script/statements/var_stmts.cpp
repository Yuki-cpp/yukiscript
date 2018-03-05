#include "var_stmts.hpp"

#include <iostream>

#include "context_stack.hpp"



yuki::statements::literal_stmt::literal_stmt(const yuki::type::variable& literal) :
	m_var(literal)
{}


yuki::type::variable yuki::statements::literal_stmt::evaluate(yuki::context::context_stack& stack)
{
	(void)stack;
	return m_var;
}



yuki::statements::get_var_stmt::get_var_stmt(const std::string& identifier) : 
m_identifier(identifier)
{}

yuki::type::variable yuki::statements::get_var_stmt::evaluate(yuki::context::context_stack& stack)
{
	return stack.current_context().get_variable(m_identifier);
}


yuki::statements::def_var_stmt::def_var_stmt(const std::string& identifier):
m_identifier(identifier)
{}


void yuki::statements::def_var_stmt::execute(yuki::context::context_stack& stack)
{
	stack.current_context().declare_variable(m_identifier, std::make_unique<yuki::type::variable>());
}




yuki::statements::set_stmt::set_stmt(const std::string& identifier, std::unique_ptr<evaluable_stmt> && rhs):
m_identifier(identifier),
m_rhs(std::move(rhs))
{}


void yuki::statements::set_stmt::execute(yuki::context::context_stack& stack)
{
	stack.current_context().get_variable(m_identifier) = m_rhs->evaluate(stack);
}


yuki::statements::print_stmt::print_stmt(std::unique_ptr<evaluable_stmt> && value):
m_value(std::move(value))
{}


void yuki::statements::print_stmt::execute(yuki::context::context_stack& stack)
{
	std::cout << m_value->evaluate(stack);
}
