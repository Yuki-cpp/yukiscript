#ifndef YUKI_SCRIPT_TYPE_SUPPORT_TYPE_SUPPORT_HPP
#define YUKI_SCRIPT_TYPE_SUPPORT_TYPE_SUPPORT_HPP

#include <variant>
#include <string>

/**
* @brief namespace used for internal types support utilities
*
*/
namespace yuki::type::internal
{

/**
* @brief Internal type representation
*
* It holds all the types supported by yuki script.
* nullptr_t is used to represent a nil value (equivalent to NaN)
*/
using type = std::variant<int, double, bool, char, std::string, std::nullptr_t>;


/**
* @brief Generic visitor template
* 
* This template provide a base on which visitors for \ref type can be built
*/
template <typename... Ts>
struct type_visitor : Ts...
{
	using Ts::operator()...;
};

template <typename... Ts>
type_visitor(Ts...) -> type_visitor<Ts...>;


}




#endif
