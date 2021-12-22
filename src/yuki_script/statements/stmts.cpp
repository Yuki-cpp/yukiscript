#include "stmts.hpp"

#include <vector>
#include <memory>

#include "type_support/variable.hpp"
#include "context/context.hpp"
#include "context/context_stack.hpp"


yuki::statements::compound_stmt::compound_stmt(std::vector<std::unique_ptr<executable_stmt> > && sub_statements):
	m_sub_statements(std::move(sub_statements))
{}


void yuki::statements::compound_stmt::execute(yuki::context::context_stack& stack)
{
	yuki::context::context_block_guard guard(stack.current_context());
	for(const auto & statement : m_sub_statements)
	{
		statement->execute(stack);
	}

}


void yuki::statements::evaluable_stmt::execute(yuki::context::context_stack& stack)
{
	evaluate(stack);
}
