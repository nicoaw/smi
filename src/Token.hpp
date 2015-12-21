#ifndef TOKEN_HPP
#define TOKEN_HPP

enum class Operator
{
	// Order determines precedence
	LeftParenthesis,
	RightParenthesis,
	Exclamation,
	Caret,
	Asterix,
	Slash,
	Percent,
	Plus,
	Minus,
	Equals,
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
		struct
		{
			Value* memory;
			Value value;
		};

		Operator op;
	};
};

#endif /* TOKEN_HPP */
