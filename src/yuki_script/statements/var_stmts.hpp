#ifndef YUKI_SCRIPT_STMTS_VAR_STMTS_HPP
#define YUKI_SCRIPT_STMTS_VAR_STMTS_HPP


#include <string>

#include "stmts.hpp"
#include "type_support/variable.hpp"

namespace yuki::statements
{


class literal_stmt : public yuki::statements::evaluable_stmt
{
public:
	explicit literal_stmt(const yuki::type::variable & literal);
	yuki::type::variable evaluate(yuki::context::context_stack & stack) override;

private:
	yuki::type::variable m_var;
};



class get_var_stmt : public yuki::statements::evaluable_stmt
{
public:
	explicit get_var_stmt(const std::string & identifier);
	yuki::type::variable evaluate(yuki::context::context_stack & stack) override;

private:
	std::string m_identifier;
};


class def_var_stmt : public yuki::statements::executable_stmt
{
public:
	explicit def_var_stmt(const std::string & identifier);
	void execute(yuki::context::context_stack & stack) override;

private:
	std::string m_identifier;
};




class set_stmt : public yuki::statements::executable_stmt
{
public:
	explicit set_stmt(const std::string & identifier, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
	void execute(yuki::context::context_stack & stack) override;

private:
	std::string m_identifier;
	std::unique_ptr<yuki::statements::evaluable_stmt> m_rhs;
};


class print_stmt : public yuki::statements::executable_stmt
{
public:
	explicit print_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && value);
	void execute(yuki::context::context_stack & stack) override;
private:
	std::unique_ptr<yuki::statements::evaluable_stmt> m_value;
};





}








#endif
