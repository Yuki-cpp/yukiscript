#ifndef YUKI_SCRIPT_TYPE_SUPPORT_MULTIPLICATION_SUPPORT_HPP
#define YUKI_SCRIPT_TYPE_SUPPORT_MULTIPLICATION_SUPPORT_HPP


#include <string>

#include "type_support.hpp"


namespace yuki::type::internal
{

/**
* @brief Template variable indicating if 2 types are compatible relative to the multiplication operator
* false by default it can be specialized to true to allow this operation
*
*/
template<typename T, typename U>
constexpr bool  are_multiplicable = false;

template<> constexpr bool  are_multiplicable<int, int> = true;
template<> constexpr bool  are_multiplicable<int, double> = true;
template<> constexpr bool  are_multiplicable<int, char> = true;

template<> constexpr bool  are_multiplicable<double, int> = true;
template<> constexpr bool  are_multiplicable<double, double> = true;
template<> constexpr bool  are_multiplicable<double, char> = true;

template<> constexpr bool  are_multiplicable<char, int> = true;
template<> constexpr bool  are_multiplicable<char, double> = true;
template<> constexpr bool  are_multiplicable<char, char> = true;




/**
* @brief Function performing the actual multiplication operation between two elements
*
*
* @param T p_T:Type of the first element
* @param U p_U:Type of the second element
* @param lhs p_lhs:First element (left hand side)
* @param rhs p_rhs:Second element (right hand side)
* @return yuki::type::internal::type The result of the operation. Returns nullptr if the 2 elements are not compatible according to \ref are_multiplicable
*/
template<typename T, typename U>
inline yuki::type::internal::type multiply(const T & lhs, const U & rhs)
{
	if constexpr(! are_multiplicable<T, U>)
	{
		return nullptr;
	}
	else
	{
		return lhs * rhs;
	}
}

/**
* @brief Specialized visitor performing a multiplication between two elements
*
*/
inline yuki::type::internal::type_visitor multiplication_visitor
{
	[](auto & t1, auto & t2)
	{
		return multiply(t1, t2);
	}
};


}



#endif
