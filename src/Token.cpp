#include "Token.hpp"

using namespace std;

istream& operator>>(istream& is, Token& token)
{
	char c;
	is >> c;

	switch(c)
	{
		case '*':
			token.type = Token::Type::Asterix;
			break;
		case '^':
			token.type = Token::Type::Caret;
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
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			is.putback(c);
			is >> token.real;
			token.type = Token::Type::Real;
			break;
		default:
			is.setstate(ios::failbit);
	}

	return is;
}

