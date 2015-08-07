#include "Debug.hpp"

using namespace std;

void printToken(const Token& token)
{
	switch(token.type)
	{
		case Token::Type::Asterix:
			cout << "*";
			break;
		case Token::Type::Caret:
			cout << "^";
			break;
		case Token::Type::Equals:
			cout << "=";
			break;
		case Token::Type::LeftParenthesis:
			cout << "(";
			break;
		case Token::Type::Minus:
			cout << "-";
			break;
		case Token::Type::Mod:
			cout << "%";
			break;
		case Token::Type::Name:
			cout << token.name;
			break;
		case Token::Type::Plus:
			cout << "+";
			break;
		case Token::Type::Real:
			cout << token.real;
			break;
		case Token::Type::RightParenthesis:
			cout << ")";
			break;
		case Token::Type::Slash:
			cout << "/";
			break;
	}
}
