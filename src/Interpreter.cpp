#include "Interpreter.hpp"
#include <cassert>
#include <cmath>
#include <stack>

Value Interpreter::evaluate(const std::vector<Token>& postfixExpression)
{
	std::stack<Token> operands; 

	for(const Token& token : postfixExpression)
	{
		switch(token.type)
		{
			case Token::Type::Memory:
			case Token::Type::Value:
				operands.push(token);
				break;
			case Token::Type::Operator:
				{
					Token right = operands.top();
					operands.pop();

					switch(token.op)
					{
						case Operator::Asterix:
							operands.top().value *= right.value;
							break;
						case Operator::Caret:
							operands.top().value = std::pow(operands.top().value, right.value);
							break;
						case Operator::Equals:
							*operands.top().memory = right.value;
							operands.top().value = right.value;
							break;
						case Operator::Exclamation:
							right.value = factorial(right.value);
							operands.push(right);
							break;
						case Operator::Minus:
							if(operands.empty())
							{
								right.value *= -1;
								operands.push(right);
							}
							else
								operands.top().value -= right.value;
							break;
						case Operator::Percent:
							operands.top().value = std::fmod(operands.top().value, right.value);
							break;
						case Operator::Plus:
							operands.top().value += right.value;
							break;
						case Operator::Slash:
							operands.top().value /= right.value;
							break;
						default: assert(false); break;
					}
				}
				break;
		}						
	}

	return operands.empty() ? 0 : operands.top().value;
}

unsigned long long Interpreter::factorial(unsigned long long n)
{
	unsigned long long result{n};
	while(n > 1)
		result *= --n;
	return result;
}

Value Interpreter::interpret(std::istream& is)
{
	std::vector<Token> expression;

	// Get expression in postfix notation
	parse(is, expression);
	postfix(expression);

	return evaluate(expression);
}

void Interpreter::parse(std::istream& is, std::vector<Token>& expression)
{
	while(is)
	{
		Token token{Token::Type::Operator, {}};

		switch(is.peek())
		{
			case '*':
				token.op = Operator::Asterix;
				is.get();
				break;
			case '^':
				token.op = Operator::Caret;
				is.get();
				break;
			case '=':
				token.op = Operator::Equals;
				is.get();
				break;
			case '!':
				token.op = Operator::Exclamation;
				is.get();
				break;
			case '(':
				token.op = Operator::LeftParenthesis;
				is.get();
				break;
			case '%':
				token.op = Operator::Percent;
				is.get();
				break;
			case '+':
				token.op = Operator::Plus;
				is.get();
				break;
			case ')':
				token.op = Operator::RightParenthesis;
				is.get();
				break;
			case '/':
				token.op = Operator::Slash;
				is.get();
				break;
				// Only extract minus as an operator if it is used for subtraction
			case '-':
				if(expression.empty() || expression.back().type == Token::Type::Value || expression.back().type == Token::Type::Memory || expression.back().op == Operator::RightParenthesis)
				{
					token.op = Operator::Minus;
					is.get();
				}
				break;
				// Ignore spaces
			case ' ':
			case '\t':
				is.get();
				continue;
			case '\n':
				is.get();
				return;
			default:
				// Token is a name
				if(std::isalpha(is.peek()))
				{
					std::string name;

					// Get name
					while(std::isalnum(is.peek()) || is.peek() == '_')
						name.push_back(is.get());

					token.type = Token::Type::Memory;
					token.memory = &memory[name];
					token.value = *token.memory;
				}
				else
				{
					// Token is a number
					if(is >> token.value)
						token.type = Token::Type::Value;
					else
						assert(false);
				}
				break;
		}

		if(is) expression.push_back(token);
	}
}

void Interpreter::postfix(std::vector<Token>& expression)
{
	std::stack<Token> operators;
	auto result = expression.begin();

	auto popOperator = [&operators]()
	{
		Token temporary = operators.top();
		operators.pop();
		return temporary;
	};

	for(const Token& token : expression)
	{	
		switch(token.type)
		{
			case Token::Type::Memory:
			case Token::Type::Value:
				*(result++) = token;
				break;
			case Token::Type::Operator:
				switch(token.op)
				{
					case Operator::RightParenthesis:
						// Push operators untill a left parenthesis
						while(operators.top().op != Operator::LeftParenthesis)
							*(result++) = popOperator();
						operators.pop();
						break;
					default:
						// Push operators untill there is no more, opertor is a left parenthesis, or operator is lower precedence compared to the current token
						while(!operators.empty() && operators.top().op != Operator::LeftParenthesis && token.op >= operators.top().op)
							*(result++) = popOperator();
						operators.push(token);
						break;
				}
				break;
		}
	}

	// Push the rest of the operators
	while(!operators.empty())
		*(result++) = popOperator();
	// Remove any excess space because parenthesis are skipped
	expression.erase(result, expression.end());
}
