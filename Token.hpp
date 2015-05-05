#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "Number.hpp"
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
		Number,
		Plus,
		RightParenthesis,
		Slash,
	};

	Type type;

	union
	{
		Number number;
	};
};

std::istream& operator>>(std::istream& is, Token& token);

#endif /* TOKEN_HPP */
