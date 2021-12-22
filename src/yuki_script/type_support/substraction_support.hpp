#ifndef YUKI_SCRIPT_TYPE_SUPPORT_SUBSTRACTION_SUPPORT_HPP
#define YUKI_SCRIPT_TYPE_SUPPORT_SUBSTRACTION_SUPPORT_HPP


#include <string>

#include "type_support.hpp"


namespace yuki::type::internal
{

/**
* @brief Template variable indicating if 2 types are compatible relative to the substraction operator
* false by default it can be specialized to true to allow this operation
*
*/
template<typename T, typename U>
constexpr bool  are_substractable = false;

template<> constexpr inline bool  are_substractable<int, int> = true;
template<> constexpr inline bool  are_substractable<int, double> = true;
template<> constexpr inline bool  are_substractable<int, char> = true;

template<> constexpr inline bool  are_substractable<double, int> = true;
template<> constexpr inline bool  are_substractable<double, double> = true;
template<> constexpr inline bool  are_substractable<double, char> = true;

template<> constexpr inline bool  are_substractable<char, int> = true;
template<> constexpr inline bool  are_substractable<char, double> = true;
template<> constexpr inline bool  are_substractable<char, char> = true;




/**
* @brief Function performing the actual substraction operation between two elements
*
*
* @param T p_T:Type of the first element
* @param U p_U:Type of the second element
* @param lhs p_lhs:First element (left hand side)
* @param rhs p_rhs:Second element (right hand side)
* @return yuki::type::internal::type The result of the operation. Returns nullptr if the 2 elements are not compatible according to \ref are_substractable
*/
template<typename T, typename U>
inline yuki::type::internal::type substract(const T & lhs, const U & rhs)
{
	if constexpr(! are_substractable<T, U>)
	{
		return nullptr;
	}
	else
	{
		return lhs - rhs;
	}
}




/**
* @brief Specialized visitor performing a substraction between two elements
*
*/
inline const yuki::type::internal::type_visitor substraction_visitor
{
	[](auto & t1, auto & t2)
	{
		return substract(t1, t2);
	}
};



/**
* @brief Specialized visitor performing the negation of a single element
*
*/
inline const yuki::type::internal::type_visitor neg_visitor
{
	[](auto & t1)
	{
		return substract(t1, 0);
	}
};




}




#endif
