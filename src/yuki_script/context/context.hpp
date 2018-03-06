#ifndef YUKI_SCRIPT_CONTEXT_CONTEXT_HPP
#define YUKI_SCRIPT_CONTEXT_CONTEXT_HPP


#include <map>
#include <string>
#include <vector>
#include <memory>

#include "type_support/variable.hpp"

#include "statements/stmts.hpp"

namespace yuki::context
{

class context
{
public:

	using function_t = std::tuple<yuki::statements::executable_stmt*, std::vector<std::string>>;


	explicit context();
	context(const context & other) = delete;
	context& operator=(const context & other) = delete;
	context(context && other) = default;
	context& operator=(context && other) = default;


	void declare_variable(const std::string & identifier, std::unique_ptr<yuki::type::variable>&& var);
	yuki::type::variable & get_variable(const std::string & identifier) const;


	void declare_function(const std::string & identifier, yuki::statements::executable_stmt* body, const std::vector<std::string> & args);
	function_t get_function(const std::string & identifier) const;

	void push_block();
	void pop_block();

	bool is_function_declared(const std::string & identifier, bool current_scope_only = true) const;
	bool is_variable_declared(const std::string & identifier, bool current_scope_only = true) const;

private:
	using variable_block_context = std::map<std::string, std::unique_ptr<yuki::type::variable>>;
	using function_block_context = std::map<std::string, function_t>;

	std::vector<variable_block_context> m_known_variables;
	std::vector<function_block_context> m_known_functions;
};


class context_block_guard
{
public:
	explicit context_block_guard(yuki::context::context & c);
	~context_block_guard();

private:
	yuki::context::context & m_context;
};


}


















#endif
