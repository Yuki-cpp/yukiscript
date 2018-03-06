#include "function_stmts.hpp"

#include "context_stack.hpp"
#include "context.hpp"

namespace
{
template <typename... Ts>
struct evaluator : Ts...
{
	using Ts::operator()...;
};

template <typename... Ts>
evaluator(Ts...) -> evaluator<Ts...>;
}



yuki::statements::call_function_stmt::call_function_stmt(const std::string & identifier, std::vector<function_arg_t> && args):
m_identifier(identifier),
m_args(std::move(args))
{}




yuki::type::variable yuki::statements::call_function_stmt::evaluate(yuki::context::context_stack& stack)
{
	auto & base_context = stack.current_context();
	auto [body, function_args] = stack.get_function(m_identifier);

	if(body && function_args.size() == m_args.size())
	{
		yuki::context::context function_context;
		function_context.declare_variable("ret", std::make_unique<yuki::type::variable>());

		//Set up arguments
		evaluator args_evaluator
		{
			[&stack](const std::string & value)
			{
				return stack.get_variable(value);
			},
			[&stack](std::unique_ptr<yuki::statements::evaluable_stmt> & value)
			{
				return value->evaluate(stack);
			}
		};

		for(auto i = 0u ; i < function_args.size() ; ++i)
		{
			function_context.declare_variable(function_args[i], std::make_unique<yuki::type::variable>(std::visit(args_evaluator, m_args[i])));
		}

		stack.push(std::move(function_context));
		body->execute(stack);

		for(auto i = 0u ; i < function_args.size() ; ++i)
		{
			auto var = stack.current_context().get_variable(function_args[i]);
			//Update arguments
			evaluator update_args_evaluator
			{
				[&var, &base_context](const std::string & value)
				{
					base_context.get_variable(value) = var;
				},
				[](std::unique_ptr<yuki::statements::evaluable_stmt> & value)
				{
					(void)value;
				}
			};
			std::visit(update_args_evaluator, m_args[i]);

		}

		auto return_value = stack.current_context().get_variable("ret");
		stack.pop();

		return return_value;
	}
	return {};
}





yuki::statements::def_function_stmt::def_function_stmt(const std::string & identifier, std::vector<std::string> && args, std::unique_ptr<yuki::statements::executable_stmt> && body):
m_identifier(identifier),
m_args(std::move(args)),
m_body(std::move(body))
{}


void yuki::statements::def_function_stmt::execute(yuki::context::context_stack& stack)
{
	stack.current_context().declare_function(m_identifier, m_body.get(), m_args);
}



