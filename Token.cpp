#include "Token.hpp"

using namespace std;

istream& operator>>(istream& is, Token& token)
{
	char c;
	is.get(c);

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

			is >> token.number;
			token.type = Token::Type::Number;
			break;
			//default error
	}

	return is;
}

