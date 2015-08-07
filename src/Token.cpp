#include "Token.hpp"
#include <map>

using namespace std;

unsigned int Token::getPrecedence(Token::Type type)
{
	static map<Token::Type, int> precedences
	{
		{ Token::Type::Minus, 0 },
		{ Token::Type::ExclamationPoint, 0 },
		{ Token::Type::Caret, 0 },
		{ Token::Type::Asterix, 2 },
		{ Token::Type::Slash, 2 },
		{ Token::Type::Mod, 2 },
		{ Token::Type::Plus, 3 },
		{ Token::Type::Equals, 4 },
	};

	auto position = precedences.find(type);
	
	if(position != precedences.end())
		return position->second;
	else
		throw std::runtime_error{"Unable to determine token precedence"};
}

bool Token::isOperand(const Token& token)
{
	return token.type == Token::Type::Name || token.type == Token::Type::Real;
}

bool Token::isOperator(const Token& token)
{
	return !isOperand(token);
}

istream& operator>>(istream& is, Token& token)
{
	char c;
	is >> c;

	if(isdigit(c))
	{
		is.putback(c);
		is >> token.real;
		token.type = Token::Type::Real;
	}
	else if(isalpha(c))
	{
		token.type = Token::Type::Name;	
		token.name = c;
		while(is.peek() != EOF && (isalpha(is.peek()) || isdigit(is.peek())))
			token.name.push_back(is.get());
	}
	else
	{
		switch(c)
		{
			case '*':
				token.type = Token::Type::Asterix;
				break;
			case '^':
				token.type = Token::Type::Caret;
				break;
			case '=':
				token.type = Token::Type::Equals;
				break;
			case '!':
				token.type = Token::Type::ExclamationPoint;
				break;
			case '(':
				token.type = Token::Type::LeftParenthesis;
				break;
			case '-':
				token.type = Token::Type::Minus;
				break;
			case '%':
				token.type = Token::Type::Mod;
				break;
			case '+':
				token.type = Token::Type::Plus;
				break;
			case ')':
				token.type = Token::Type::RightParenthesis;
				break;
			case '/':
				token.type = Token::Type::Slash;
				break;
			default:
				is.setstate(ios::failbit);
		}
	}

	return is;
}
