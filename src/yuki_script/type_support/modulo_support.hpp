#ifndef YUKI_SCRIPT_TYPE_SUPPORT_MODULO_SUPPORT_HPP
#define YUKI_SCRIPT_TYPE_SUPPORT_MODULO_SUPPORT_HPP


#include <string>

#include "type_support.hpp"


namespace yuki::type::internal
{

/**
* @brief Template variable indicating if 2 types are compatible relative to the modulo operator
* false by default it can be specialized to true to allow this operation
*
*/
template<typename T, typename U>
constexpr bool  are_modulable = false;

template<> constexpr inline bool  are_modulable<int, int> = true;
template<> constexpr inline bool  are_modulable<int, char> = true;

template<> constexpr inline bool  are_modulable<char, int> = true;
template<> constexpr inline bool  are_modulable<char, char> = true;










/**
* @brief Function performing the actual modulo operation between two elements
*
*
* @param T p_T:Type of the first element
* @param U p_U:Type of the second element
* @param lhs p_lhs:First element (left hand side)
* @param rhs p_rhs:Second element (right hand side)
* @return yuki::type::internal::type The result of the operation. Returns nullptr if the 2 elements are not compatible according to \ref are_modulable
*/
template<typename T, typename U>
inline yuki::type::internal::type modulo(const T & lhs, const U & rhs)
{
	if constexpr(! are_modulable<T, U>)
	{
		return nullptr;
	}
	else
	{
		return lhs % rhs;
	}
}

/**
* @brief Specialized visitor performing a modulo operation between two elements
*
*/
inline const yuki::type::internal::type_visitor modulo_visitor
{
	[](auto & t1, auto & t2)
	{
		return modulo(t1, t2);
	}
};




}




#endif
