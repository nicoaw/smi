#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "Operator.hpp"
#include <iostream>
#include <vector>

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

long double evaluate(const std::vector<Token>& tokens);
std::istream& operator>>(std::istream& is, Token& token);
std::ostream& operator<<(std::ostream& is, const Token& token);
void postfix(std::vector<Token>& tokens); // Convert to postfix notation

#endif /* TOKEN_HPP */
