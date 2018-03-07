#include "control_stmts.hpp"


yuki::statements::while_stmt::while_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> condition, std::unique_ptr<yuki::statements::compound_stmt> body):
m_condition(std::move(condition)),
m_body(std::move(body))
{}


void yuki::statements::while_stmt::execute(yuki::context::context_stack& stack)
{
	while(m_condition->evaluate(stack))
	{
		m_body->execute(stack);
	}
}


yuki::statements::if_stmt::if_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> condition, std::unique_ptr<yuki::statements::compound_stmt> body, std::unique_ptr<yuki::statements::compound_stmt> else_body):
m_condition(std::move(condition)),
m_body(std::move(body)),
m_else_body(std::move(else_body))
{}


void yuki::statements::if_stmt::execute(yuki::context::context_stack& stack)
{
	if(m_condition->evaluate(stack))
	{
		m_body->execute(stack);
	}
	else if(m_else_body)
	{
		m_else_body->execute(stack);
	}
}
