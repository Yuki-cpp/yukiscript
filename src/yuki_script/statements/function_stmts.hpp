#ifndef YUKI_SCRIPT_STMTS_FUNCTION_STMTS_HPP
#define YUKI_SCRIPT_STMTS_FUNCTION_STMTS_HPP

#include <variant>

#include "stmts.hpp"





namespace yuki::statements
{

using function_arg_t = std::variant<std::string, std::unique_ptr<evaluable_stmt>>;


class call_function_stmt : public evaluable_stmt
{
public:
	explicit call_function_stmt(const std::string & identifier, std::vector<function_arg_t> && args );
	yuki::type::variable evaluate(yuki::context::context_stack & stack) override;

private:
	std::string m_identifier;
	std::vector<function_arg_t> m_args;
};





class def_function_stmt : public executable_stmt
{
public:
	explicit def_function_stmt(const std::string & identifier, std::vector<std::string> && args, std::unique_ptr<executable_stmt> && body );
	void execute(yuki::context::context_stack & stack) override;

private:
	std::string m_identifier;
	std::vector<std::string> m_args;
	std::unique_ptr<executable_stmt> m_body;
};






}






#endif
