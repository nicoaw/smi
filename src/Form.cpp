#include "Form.hpp"
#include <stack>

using namespace std;

void postfix(vector<Token>& tokens)
{
	stack<Token> operators;
	auto position = tokens.begin();
	auto pop = [&operators]()
	{
		auto temp = operators.top();
		operators.pop();
		return temp;
	};
	auto comparePrecedence = [](const Token& lhs, const Token& rhs)
	{
		return Token::getPrecedence(lhs.type) <= Token::getPrecedence(rhs.type);
	};

	for(const Token& token : tokens)
	{
		if(Token::isOperator(token))
		{
			if(token.type == Token::Type::RightParenthesis)
			{
				while(operators.top().type != Token::Type::LeftParenthesis)
					*(position++) = pop();

				operators.pop();	
			}
			else
			{
				if(token.type != Token::Type::LeftParenthesis)
					while(!operators.empty() && operators.top().type != Token::Type::LeftParenthesis && !comparePrecedence(token, operators.top()))
						*(position++) = pop();

				operators.push(token);
			}
		}
		else
			*(position++) = token;
	}

	while(!operators.empty())
		*(position++) = pop();

	tokens.erase(position, tokens.end());
}
