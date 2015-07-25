#include "Interpreter.hpp"
#include <cmath>
#include <stdexcept>

using namespace std;

Real Interpreter::exp(bool next)
{
	Real left = prim(next);

	while(true)
	{
		switch(it->type)
		{
			case Token::Type::Caret:
				left = pow(left, prim(true));
				break;
			default:
				return left;
		}
	}
}

Real Interpreter::expr(bool next)
{
	Real left = term(next);

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

Real Interpreter::interpret(const std::string& expression)
{
	iss.clear();
	iss.str(expression);
	it = {iss};
	skipws(iss);	

	return expr(false);
}

Real Interpreter::prim(bool next)
{
	if(next)
		++it;

	switch(it->type)
	{
		case Token::Type::Name:
			{
				Real& value = constants[it->name];
				++it;

				if(it->type == Token::Type::Equals)
					value = expr(true);

				return value;
			}
		case Token::Type::Real:
			{
				Real num = it->real;
				++it;
				return num;
			}
		case Token::Type::Minus:
			return -prim(true);
		case Token::Type::LeftParenthesis:
			{
				Real num = expr(true);

				if(it->type != Token::Type::RightParenthesis)
					throw invalid_argument{"right parenthesis expected"};

				++it;
				return num;
			}
		default:
			throw invalid_argument{"primary expected"};
			break;
	}
}

void Interpreter::setValue(const std::string& name, Real value)
{
	constants[name] = value;
}

Real Interpreter::term(bool next)
{
	auto left = exp(next);

	while(true)
	{
		switch(it->type)
		{
			case Token::Type::Asterix:
				left *= exp(true);
				break;
			case Token::Type::Mod:
				left = fmod(left, exp(true));
				break;
			case Token::Type::Slash:
				left /= exp(true);
				break;
			default:
				return left;
		}
	}
}
