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
	variable()=default;

	explicit variable(std::nullptr_t)
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
	
	variable operator&&(const variable & other) const;
	variable operator||(const variable & other) const;

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

	explicit operator bool() const;

	friend std::ostream& operator<<(std::ostream& os, const yuki::type::variable& var);

private:

	yuki::type::internal::type m_value = nullptr;
};

std::ostream& operator<<(std::ostream& os, const yuki::type::variable& var);

}


#endif














































