#ifndef YUKI_SCRIPT_STMTS_CONTROL_STMTS_HPP
#define YUKI_SCRIPT_STMTS_CONTROL_STMTS_HPP


#include "stmts.hpp"
#include "variable.hpp"

namespace yuki::statements
{


class while_stmt : public yuki::statements::executable_stmt
{
public:
	explicit while_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> condition, std::unique_ptr<yuki::statements::compound_stmt> body);
	void execute(yuki::context::context_stack & stack) override;
private:
	std::unique_ptr<yuki::statements::evaluable_stmt> m_condition;
	std::unique_ptr<yuki::statements::compound_stmt> m_body;
};


class if_stmt : public yuki::statements::executable_stmt
{
public:
	explicit if_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> condition, std::unique_ptr<yuki::statements::compound_stmt> body);
	void execute(yuki::context::context_stack & stack) override;
private:
	std::unique_ptr<yuki::statements::evaluable_stmt> m_condition;
	std::unique_ptr<yuki::statements::compound_stmt> m_body;
};


}


#endif
