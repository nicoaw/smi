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
		LeftParenthesis,
		Minus,
		Mod,
		Name,
		Plus,
		Real,
		RightParenthesis,
		Slash,
	};

	Type type;

	Real real;
	std::string name;
};

std::istream& operator>>(std::istream& is, Token& token);

#endif /* TOKEN_HPP */
