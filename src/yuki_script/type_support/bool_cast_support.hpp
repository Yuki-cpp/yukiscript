#ifndef YUKI_SCRIPT_TYPE_SUPPORT_BOOL_CAST_SUPPORT_HPP
#define YUKI_SCRIPT_TYPE_SUPPORT_BOOL_CAST_SUPPORT_HPP


#include <string>

#include "type_support.hpp"


namespace yuki::type::internal
{

/**
* @brief Cast a value to bool
*
* @param T p_T:Type of the value
* @param val p_val:value to cast
* @return bool
*/
template <typename T>
inline bool bool_cast(const T & val)
{
	return val != 0;
}


/**
* @brief Cast a string to bool
*/
inline bool bool_cast(const std::string & val)
{
	return val != "";
}

/**
* @brief Cast a nullptr_t to bool
*/
inline bool bool_cast(std::nullptr_t)
{
	return false;
}

/**
* @brief Utility function provided to ensure that the visitor can call bool_cast with any type
*/
inline bool bool_cast(bool b)
{
	return b;
}

/**
* @brief Specialized visitor casting an element to bool
*
*/
inline yuki::type::internal::type_visitor bool_cast_visitor
{
	[](auto & t1)
	{
		return bool_cast(t1);
	}
};



/**
* @brief Performes the not (!) operation on an element.
* If the lement is not a bool, return nullptr
*/
template <typename T>
inline yuki::type::internal::type not_op(const T &)
{
	return nullptr;
}


/**
* @brief Performes the not (!) operation on an element.
* If the lement is not a bool, return nullptr
*/
inline yuki::type::internal::type not_op(bool val)
{
	return !val;
}


/**
* @brief Specialized visitor performing the not operation on an element
*
*/
inline yuki::type::internal::type_visitor not_visitor
{
	[](auto & t1)
	{
		return not_op(t1);
	}
};


}




#endif




































































