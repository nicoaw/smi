#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "Real.hpp"
#include <iostream>

struct Token
{
	enum class Type
	{
		Asterix,
		Caret,
		Equals,
		ExclamationPoint,
		LeftParenthesis,
		Minus,
		Mod,
		Name,
		Plus,
		Real,
		RightParenthesis,
		Slash,
	};

	static unsigned int getPrecedence(Token::Type type);

	static bool isOperand(const Token& token);

	static bool isOperator(const Token& token);

	Type type;

	Real real;
	std::string name;
};

std::istream& operator>>(std::istream& is, Token& token);

#endif /* TOKEN_HPP */
