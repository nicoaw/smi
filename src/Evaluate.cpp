#include "Evaluate.hpp"
#include <cmath>
#include <stack>

using namespace std;

struct Operand
{
	enum class Type
	{
		Name,
		Real,
	};

	Type type;
	string name;
	Real real;
};

Real evaluate(map<string, Real>& memory, const std::vector<Token>& tokens)
{
	stack<Operand> operands;
	Operand rhs;
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
				operands.top().real *= rhs.real;
				break;
			case Token::Type::Caret:
				rhs = pop();
				operands.top().real = pow(operands.top().real, rhs.real);
				break;
			case Token::Type::Equals:
				rhs = pop();
				operands.top().real = rhs.real;
				memory[operands.top().name] = operands.top().real;
				break;
			case Token::Type::Minus:
				rhs = pop();
				operands.top().real -= rhs.real;
				break;
			case Token::Type::Mod:
				rhs = pop();
				operands.top().real = fmod(operands.top().real, rhs.real);
				break;
			case Token::Type::Name:
				operands.push(Operand{Operand::Type::Name, token.name, memory[token.name]});
				break;
			case Token::Type::Plus:
				rhs = pop();
				operands.top().real += rhs.real;
				break;
			case Token::Type::Real:
				operands.push(Operand{Operand::Type::Real, "", token.real});
				break;
			case Token::Type::Slash:
				rhs = pop();
				operands.top().real /= rhs.real;
				break;
			default:
				throw runtime_error{"Unexpected token"};
		}
	}

	return operands.top().real;
}
