#ifndef TOKEN_HPP
#define TOKEN_HPP

enum class Operator
{
	// Order determines precedence
	LeftParenthesis,
	RightParenthesis,
	Equals,
	Exclamation,
	Caret,
	Asterix,
	Slash,
	Percent,
	Plus,
	Minus,
};

using Value = long double;

struct Token
{
	enum class Type
	{
		Memory,
		Operator,
		Value,
	};

	Type type;
	
	union
	{
		Value* memory;
		Operator op;
		Value value;
	};
};

#endif /* TOKEN_HPP */
