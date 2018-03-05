#include "context_stack.hpp"

#include <cassert>
#include <stack>


#include "context.hpp"


yuki::context::context_stack::context_stack()
{
	m_contexts.emplace_back();
}


void yuki::context::context_stack::push(yuki::context::context && c)
{
	m_contexts.emplace_back(std::move(c));
}


yuki::context::context & yuki::context::context_stack::current_context()
{
	return m_contexts.back();
}

std::size_t yuki::context::context_stack::size() const
{
	return m_contexts.size();
}


void yuki::context::context_stack::pop()
{
	assert(m_contexts.size() > 1);
	m_contexts.pop_back();
}

yuki::context::context::function_t yuki::context::context_stack::get_function(const std::string& identifier) const
{
	for(auto it = m_contexts.rbegin(); it != m_contexts.rend(); ++it)
	{
		if(it->is_function_declared(identifier))
		{
			return it->get_function(identifier);
		}
	}
	throw std::runtime_error(identifier + " was not declared declared in this scope");
}

yuki::type::variable & yuki::context::context_stack::get_variable(const std::string& identifier) const
{
	if(m_contexts.back().is_variable_declared(identifier))
	{
		return m_contexts.back().get_variable(identifier);
	}
	else if(m_contexts.front().is_variable_declared(identifier))
	{
		return m_contexts.front().get_variable(identifier);
	}

	throw std::runtime_error(identifier + " was not declared declared in this scope");
}
