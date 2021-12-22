#ifndef YUKI_SCRIPT_TYPE_SUPPORT_COMPARAISON_SUPPORT_HPP
#define YUKI_SCRIPT_TYPE_SUPPORT_COMPARAISON_SUPPORT_HPP


#include <string>

#include "type_support.hpp"


namespace yuki::type::internal
{

/**
* @brief Template variable indicating if 2 types are compatible relative to the comparaison operator
* false by default it can be specialized to true to allow this operation
*
*/
template<typename T, typename U>
constexpr bool  are_comparable = false;

template<> constexpr inline bool  are_comparable<int, int> = true;
template<> constexpr inline bool  are_comparable<int, double> = true;
template<> constexpr inline bool  are_comparable<int, char> = true;

template<> constexpr inline bool  are_comparable<double, int> = true;
template<> constexpr inline bool  are_comparable<double, double> = true;
template<> constexpr inline bool  are_comparable<double, char> = true;

template<> constexpr inline bool  are_comparable<char, int> = true;
template<> constexpr inline bool  are_comparable<char, double> = true;
template<> constexpr inline bool  are_comparable<char, char> = true;

template<> constexpr inline bool  are_comparable<bool, bool> = true;
template<> constexpr inline bool  are_comparable<std::string, std::string> = true;

/**
* @brief Function performing the actual equality comparaison operation between two elements
*
*
* @param T p_T:Type of the first element
* @param U p_U:Type of the second element
* @param lhs p_lhs:First element (left hand side)
* @param rhs p_rhs:Second element (right hand side)
* @return yuki::type::internal::type The result of the operation. Returns nullptr if the 2 elements are not compatible according to \ref are_comparable
*/
template<typename T, typename U>
inline yuki::type::internal::type equals(const T & lhs, const U & rhs)
{
	if constexpr(! are_comparable<T, U>)
	{
		return nullptr;
	}
	else
	{
		return lhs == rhs;
	}
}


/**
* @brief Specialized visitor performing a equality comparaison between two elements
*
*/
inline yuki::type::internal::type_visitor eq_visitor
{
	[](auto & t1, auto & t2)
	{
		return equals(t1, t2);
	}
};




/**
* @brief Function performing the actual lesser than comparaison operation between two elements
*
*
* @param T p_T:Type of the first element
* @param U p_U:Type of the second element
* @param lhs p_lhs:First element (left hand side)
* @param rhs p_rhs:Second element (right hand side)
* @return yuki::type::internal::type The result of the operation. Returns nullptr if the 2 elements are not compatible according to \ref are_comparable
*/
template<typename T, typename U>
inline yuki::type::internal::type lesser_than(const T & lhs, const U & rhs)
{
	if constexpr(! are_comparable<T, U>)
	{
		return nullptr;
	}
	else
	{
		return lhs < rhs;
	}
}


/**
* @brief Specialized visitor performing a lesser than comparaison between two elements
*
*/
inline const yuki::type::internal::type_visitor l_visitor
{
	[](auto & t1, auto & t2)
	{
		return lesser_than(t1, t2);
	}
};



}



#endif











































































