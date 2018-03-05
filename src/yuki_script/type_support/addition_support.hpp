#ifndef YUKI_SCRIPT_TYPE_SUPPORT_ADDITION_SUPPORT_HPP
#define YUKI_SCRIPT_TYPE_SUPPORT_ADDITION_SUPPORT_HPP


#include <string>

#include "type_support.hpp"


namespace yuki::type::internal
{

/**
* @brief Template variable indicating if 2 types are compatible relative to the addition operator
* false by default it can be specialized to true to allow this operation
*
*/
template<typename T, typename U>
constexpr bool  are_aditionable = false;

template<> constexpr bool  are_aditionable<int, int> = true;
template<> constexpr bool  are_aditionable<int, double> = true;
template<> constexpr bool  are_aditionable<int, char> = true;

template<> constexpr bool  are_aditionable<double, int> = true;
template<> constexpr bool  are_aditionable<double, double> = true;
template<> constexpr bool  are_aditionable<double, char> = true;

template<> constexpr bool  are_aditionable<char, int> = true;
template<> constexpr bool  are_aditionable<char, double> = true;
template<> constexpr bool  are_aditionable<char, char> = true;

template<> constexpr bool  are_aditionable<std::string, std::string> = true;

/**
* @brief Function performing the actual addition operation between two elements
*
*
* @param T p_T:Type of the first element
* @param U p_U:Type of the second element
* @param lhs p_lhs:First element (left hand side)
* @param rhs p_rhs:Second element (right hand side)
* @return yuki::type::internal::type The result of the operation. Returns nullptr if the 2 elements are not compatible according to \ref are_aditionable
*/
template<typename T, typename U>
inline yuki::type::internal::type add(const T & lhs, const U & rhs)
{
	if constexpr(!are_aditionable<T, U>)
	{
		return nullptr;
	}
	else
	{
		return lhs + rhs;
	}
}


/**
* @brief Specialized visitor performing a addition between two elements
*
*/
inline yuki::type::internal::type_visitor addition_visitor
{
	[](auto & t1, auto & t2)
	{
		return add(t1, t2);
	}
};

}




#endif
