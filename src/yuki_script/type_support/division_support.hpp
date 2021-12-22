#ifndef YUKI_SCRIPT_TYPE_SUPPORT_DIVISION_SUPPORT_HPP
#define YUKI_SCRIPT_TYPE_SUPPORT_DIVISION_SUPPORT_HPP


#include <string>

#include "type_support.hpp"


namespace yuki::type::internal
{

/**
* @brief Template variable indicating if 2 types are compatible relative to the division operator
* false by default it can be specialized to true to allow this operation
*
*/
template<typename T, typename U>
constexpr bool  are_dividable = false;

template<> constexpr inline bool  are_dividable<int, int> = true;
template<> constexpr inline bool  are_dividable<int, double> = true;
template<> constexpr inline bool  are_dividable<int, char> = true;

template<> constexpr inline bool  are_dividable<double, int> = true;
template<> constexpr inline bool  are_dividable<double, double> = true;
template<> constexpr inline bool  are_dividable<double, char> = true;

template<> constexpr inline bool  are_dividable<char, int> = true;
template<> constexpr inline bool  are_dividable<char, double> = true;
template<> constexpr inline bool  are_dividable<char, char> = true;




/**
* @brief Function performing the actual division operation between two elements
*
*
* @param T p_T:Type of the first element
* @param U p_U:Type of the second element
* @param lhs p_lhs:First element (left hand side)
* @param rhs p_rhs:Second element (right hand side)
* @return yuki::type::internal::type The result of the operation. Returns nullptr if the 2 elements are not compatible according to \ref are_dividable
*/
template<typename T, typename U>
inline yuki::type::internal::type divide(const T & lhs, const U & rhs)
{
	if constexpr(! are_dividable<T, U>)
	{
		return nullptr;
	}
	else
	{
		if(rhs == 0)
		{
			return nullptr;
		}
		return lhs * rhs;
	}
}

/**
* @brief Specialized visitor performing a division between two elements
*
*/
inline const yuki::type::internal::type_visitor division_visitor
{
	[](auto & t1, auto & t2)
	{
		return divide(t1, t2);
	}
};


}






#endif
