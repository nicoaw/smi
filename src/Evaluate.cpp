#include "Evaluate.hpp"
#include <cmath>
#include <stack>

using namespace std;

Real evaluate(map<string, Real>& memory, const std::vector<Token>& tokens)
{
	stack<Real> operands;
	Real rhs;
	auto pop = [&operands]()
	{
		auto temp = operands.top();
		operands.pop();
		return temp;
	};

	for(const Token& token : tokens)
	{
		switch(token.type)
		{
			case Token::Type::Asterix:
				rhs = pop();
				operands.top() *= rhs;
				break;
			case Token::Type::Caret:
				rhs = pop();
				operands.top() = pow(operands.top(), rhs);
				break;
			case Token::Type::Equals:
				break;
			case Token::Type::Minus:
				rhs = pop();
				operands.top() -= rhs;
				break;
			case Token::Type::Mod:
				rhs = pop();
				operands.top() = fmod(operands.top(), rhs);
				break;
			case Token::Type::Name:
				operands.push(memory[token.name]);
				break;
			case Token::Type::Plus:
				rhs = pop();
				operands.top() += rhs;
				break;
			case Token::Type::Real:
				operands.push(token.real);
				break;
			case Token::Type::Slash:
				rhs = pop();
				operands.top() /= rhs;
				break;
			default:
				throw runtime_error{"Unexpected token"};
		}
	}

	return operands.top();
}
