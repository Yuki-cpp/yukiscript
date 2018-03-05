#ifndef YUKI_SCRIPT_UNARY_OP_STMTS_HPP
#define YUKI_SCRIPT_UNARY_OP_STMTS_HPP


#include <functional>

#include "stmts.hpp"
#include "variable.hpp"


namespace yuki::statements
{

using unary_op_callback = std::function<yuki::type::variable(const yuki::type::variable &)>;

template<class T>
class unary_op_stmt : public yuki::statements::evaluable_stmt
{
public:
	explicit unary_op_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && value, T predicate):
		m_value(std::move(value)),
		m_predicate(predicate)
	{}

	yuki::type::variable evaluate(yuki::context::context_stack & stack) override
	{
		const auto & var_value = m_value->evaluate(stack);
		return m_predicate(var_value);
	}

private:
	std::unique_ptr<yuki::statements::evaluable_stmt> m_value;
	T m_predicate;

};



class unary_neg_stmt : public unary_op_stmt<unary_op_callback>
{
public:
	unary_neg_stmt(std::unique_ptr< yuki::statements::evaluable_stmt >&& value);
};

class unary_not_stmt : public unary_op_stmt<unary_op_callback>
{
public:
	explicit unary_not_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && value);
};


}




#endif
