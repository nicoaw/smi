#include "Token.hpp"

using namespace std;

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

		token.name.clear();
		do
		{
			token.name.push_back(c);
			c = is.get();
		}
		while(isalpha(c) || isdigit(c));
		is.putback(c);
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

