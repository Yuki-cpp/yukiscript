#ifndef YUKI_SCRIPT_CONTEXT_STACK_HPP
#define YUKI_SCRIPT_CONTEXT_STACK_HPP


#include <deque>
#include <stack>
#include "context.hpp"

namespace yuki::context
{

class context_stack
{
public:
	context_stack();

	void push(yuki::context::context && c);

	yuki::context::context & current_context();

	std::size_t size() const;

	void pop();

	yuki::context::context::function_t get_function(const std::string & identifier) const;
	yuki::type::variable & get_variable(const std::string& identifier) const;

private:
	std::deque<yuki::context::context> m_contexts;
};


}




#endif
