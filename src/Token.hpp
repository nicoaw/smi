#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "Operator.hpp"

struct Token
{
	enum class Type
	{
		Operand,
		Operator,
	};

	Type type;
	
	union
	{
		long double num;
		Operator op;
	};
};

#endif /* TOKEN_HPP */
