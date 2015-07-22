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
		LeftParenthesis,
		Minus,
		Mod,
		Plus,
		Real,
		RightParenthesis,
		Slash,
	};

	Type type;

	union
	{
		Real real;
	};
};

std::istream& operator>>(std::istream& is, Token& token);

#endif /* TOKEN_HPP */
