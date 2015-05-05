#include "Interpreter.hpp"
#include "Token.hpp"
#include <iterator>
#include <sstream>
#include <stack>

using namespace std;

struct Interpreter
{
	istream_iterator<Token> it;

	Number expr(bool next);

	Number prim(bool next);

	Number term(bool next);
};

Number interpret(const string& expression)
{
	istringstream iss{expression};
	Interpreter interpreter{{iss}};
	return interpreter.expr(false);
}

Number Interpreter::expr(bool next)
{
	Number left = term(next);

	while(true)
	{
		switch(it->type)
		{
			case Token::Type::Plus:
				left += term(true);
				break;
			case Token::Type::Minus:
				left -= term(true);
				break;
			default:
				return left;
		}
	}
}

Number Interpreter::prim(bool next)
{
	if(next)
		++it;

	switch(it->type)
	{
		case Token::Type::Number:
			{
				Number num = it->number;
				++it;
				return num;
			}
		case Token::Type::Minus:
			return -prim(true);
		case Token::Type::LeftParenthesis:
			{
				Number num = expr(true);
				++it;
				return num;
			}
		default:
			throw 1;
			break;
	}
}

Number Interpreter::term(bool next)
{
	auto left = prim(next);

	while(true)
	{
		switch(it->type)
		{
			case Token::Type::Asterix:
				left *= prim(true);
				break;
			case Token::Type::Slash:
				left /= prim(true);
				break;
			default:
				return left;
		}
	}
}
