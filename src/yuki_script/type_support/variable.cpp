#include "variable.hpp"

#include <iostream>
#include <variant>

#include "type_support.hpp"
#include "multiplication_support.hpp"
#include "division_support.hpp"
#include "substraction_support.hpp"
#include "modulo_support.hpp"
#include "comparaison_support.hpp"
#include "bool_cast_support.hpp"
#include "addition_support.hpp"

namespace
{
	template<typename T>
	void print(std::ostream& os, const T & val)
	{
		os << val;
	}
	
	void print(std::ostream& os, std::nullptr_t)
	{
		os << "nil";
	}
}

std::ostream& yuki::type::operator<<(std::ostream& os, const yuki::type::variable& var)
{
	yuki::type::internal::type_visitor output_evaluator
	{
		[&os](auto & t1)
		{
			return print(os, t1);
		}
	};
	std::visit(output_evaluator, var.m_value);
	return os;
}


yuki::type::variable yuki::type::variable::operator&&(const yuki::type::variable& other) const
{
	return variable(operator bool() && other.operator bool());
}


yuki::type::variable yuki::type::variable::operator||(const yuki::type::variable& other) const
{
	return variable(operator bool() || other.operator bool());
}


yuki::type::variable::operator bool() const
{
	return std::visit(yuki::type::internal::bool_cast_visitor, m_value);
}

yuki::type::variable yuki::type::variable::operator+(const yuki::type::variable& other) const
{
	return variable(std::visit(yuki::type::internal::addition_visitor, m_value, other.m_value));
}

yuki::type::variable yuki::type::variable::operator-(const yuki::type::variable& other) const
{
	return variable(std::visit(yuki::type::internal::substraction_visitor, m_value, other.m_value));
}

yuki::type::variable yuki::type::variable::operator*(const yuki::type::variable& other) const
{
	return variable(std::visit(yuki::type::internal::multiplication_visitor, m_value, other.m_value));
}

yuki::type::variable yuki::type::variable::operator/(const yuki::type::variable& other) const
{
	return variable(std::visit(yuki::type::internal::division_visitor, m_value, other.m_value));
}

yuki::type::variable yuki::type::variable::operator%(const yuki::type::variable& other) const
{
	return variable(std::visit(yuki::type::internal::modulo_visitor, m_value, other.m_value));
}


yuki::type::variable yuki::type::variable::operator-() const
{
	return variable(std::visit(yuki::type::internal::neg_visitor, m_value));
}


yuki::type::variable yuki::type::variable::operator<(const yuki::type::variable& other) const
{
	return variable(std::visit(yuki::type::internal::l_visitor, m_value, other.m_value));
}


yuki::type::variable yuki::type::variable::operator==(const yuki::type::variable& other) const
{
	return variable(std::visit(yuki::type::internal::eq_visitor, m_value, other.m_value));
}

yuki::type::variable yuki::type::variable::operator!=(const yuki::type::variable& other) const
{
	return !(*this == other);
}



yuki::type::variable yuki::type::variable::operator!() const
{
	return variable(std::visit(yuki::type::internal::not_visitor, m_value));
}



yuki::type::variable yuki::type::variable::operator>(const yuki::type::variable& other) const
{
	return !(operator<(other) || operator==(other));
}


yuki::type::variable yuki::type::variable::operator<=(const yuki::type::variable& other) const
{
	return operator<(other) || operator==(other);
}

yuki::type::variable yuki::type::variable::operator>=(const yuki::type::variable& other) const
{
	return !operator<(other);
}













