#ifndef YUKI_SCRIPT_TYPE_SUPPORT_VARIABLE_HPP
#define YUKI_SCRIPT_TYPE_SUPPORT_VARIABLE_HPP

#include <iosfwd>
#include <variant>

#include "type_support.hpp"

namespace yuki::type
{

class variable
{
public:
	variable():
		m_value(nullptr)
	{}

	variable(nullptr_t):
		m_value(nullptr)
	{}

	explicit variable(bool value):
		m_value(value)
	{}

	explicit variable(double value):
		m_value(value)
	{}

	explicit variable(int value):
		m_value(value)
	{}

	explicit variable(char value):
		m_value(value)
	{}

	explicit variable(std::string value):
		m_value(value)
	{}

	explicit variable(const yuki::type::internal::type & value):
		m_value(value)
	{}

	variable logical_or(const variable & other) const;
	variable logical_and(const variable & other) const;

	variable operator<(const variable & other) const;
	variable operator==(const variable & other) const;
	variable operator!=(const variable & other) const;
	variable operator>(const variable & other) const;
	variable operator>=(const variable & other) const;
	variable operator<=(const variable & other) const;

	variable operator+(const variable & other) const;
	variable operator-(const variable & other) const;
	variable operator/(const variable & other) const;
	variable operator*(const variable & other) const;
	variable operator%(const variable & other) const;

	variable operator-() const;
	variable operator!() const;

	operator bool() const;

	friend std::ostream& operator<<(std::ostream& os, const yuki::type::variable& var);

private:

	yuki::type::internal::type m_value;
};

std::ostream& operator<<(std::ostream& os, const yuki::type::variable& var);

}


#endif














































