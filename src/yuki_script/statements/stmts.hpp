#ifndef YUKI_SCRIPT_STMTS_STMTS_HPP
#define YUKI_SCRIPT_STMTS_STMTS_HPP

#include <vector>
#include <memory>

#include "variable.hpp"

namespace yuki::context
{
class context_stack;
}


namespace yuki::statements
{
	
class executable_stmt
{
public:
	virtual  void execute( yuki::context::context_stack & stack) = 0;
	virtual ~executable_stmt() = default;
};


class evaluable_stmt : public executable_stmt
{
public:
	virtual  yuki::type::variable evaluate( yuki::context::context_stack & stack) = 0;
	virtual ~evaluable_stmt() = default;
private:
	void execute(yuki::context::context_stack & stack) override;
};


class compound_stmt : public executable_stmt
{
public:
	explicit compound_stmt(std::vector<std::unique_ptr<executable_stmt>> &&sub_statements);
	void execute(yuki::context::context_stack & stack) override;

private:
	std::vector<std::unique_ptr<executable_stmt>> m_sub_statements;
};



}






#endif
