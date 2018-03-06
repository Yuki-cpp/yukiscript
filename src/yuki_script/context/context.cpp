#include "context.hpp"

#include <map>
#include <string>
#include <memory>
#include <algorithm>
#include <cassert>

#include "statements/stmts.hpp"


yuki::context::context::context()
{
	push_block();
}


bool yuki::context::context::is_variable_declared(const std::string& identifier, bool current_scope_only) const
{
	if(current_scope_only)
	{
		return m_known_variables.back().find(identifier) != m_known_variables.back().end();
	}

	for(auto it = m_known_variables.rbegin(); it != m_known_variables.rend(); ++it)
	{
		const variable_block_context & scope = *it;
		auto it2 = scope.find(identifier);
		if(it2 != scope.end())
		{
			return true;
		}
	}

	return false;

}

bool yuki::context::context::is_function_declared(const std::string& identifier, bool current_scope_only) const
{
	if(current_scope_only)
	{
		return m_known_functions.back().find(identifier) != m_known_functions.back().end();
	}

	for(auto it = m_known_functions.rbegin(); it != m_known_functions.rend(); ++it)
	{
		const function_block_context & scope = *it;
		auto it2 = scope.find(identifier);
		if(it2 != scope.end())
		{
			return true;
		}
	}

	return false;
}



void yuki::context::context::declare_variable(const std::string& identifier, std::unique_ptr<yuki::type::variable> && var)
{
	if(is_variable_declared(identifier))
	{
		throw std::runtime_error(identifier + " was already declared in this scope");
	}
	m_known_variables.back()[identifier] = std::move(var);
}


yuki::type::variable & yuki::context::context::get_variable(const std::string& identifier) const
{

	for(auto it = m_known_variables.rbegin(); it != m_known_variables.rend(); ++it)
	{
		const variable_block_context & scope = *it;
		auto it2 = scope.find(identifier);
		if(it2 != scope.end())
		{
			return *(it2->second);
		}
	}

	throw std::runtime_error(identifier + " was not declared declared in this scope");
}



void yuki::context::context::declare_function(const std::string& identifier, yuki::statements::executable_stmt* body, const std::vector<std::string> & args)
{
	if(is_function_declared(identifier))
	{
		throw std::runtime_error(identifier + " was already declared in this scope");
	}
	m_known_functions.back()[identifier] = std::make_tuple(std::move(body), args);
}


std::tuple<yuki::statements::executable_stmt *, std::vector<std::string> > yuki::context::context::get_function(const std::string& identifier) const
{
	for(auto it = m_known_functions.rbegin(); it != m_known_functions.rend(); ++it)
	{
		const auto & scope = *it;
		if(auto it2 = scope.find(identifier); it2 != scope.end())
		{
			return std::make_tuple(std::get<0>(it2->second), std::get<1>(it2->second));
		}
	}

	throw std::runtime_error(identifier + " was not declared declared in this scope");
}






void yuki::context::context::push_block()
{
	m_known_variables.push_back(context::variable_block_context {});
	m_known_functions.push_back(context::function_block_context {});
}

void yuki::context::context::pop_block()
{
	m_known_variables.pop_back();
	m_known_functions.pop_back();
}

yuki::context::context_block_guard::context_block_guard(yuki::context::context& c):
	m_context(c)
{
	m_context.push_block();
}

yuki::context::context_block_guard::~context_block_guard()
{
	m_context.pop_block();
}

