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
							operandValue(operands.top()) *= operandValue(right);
							break;
						case Operator::Caret:
							operandValue(operands.top()) = std::pow(operandValue(operands.top()), operandValue(right));
							break;
						case Operator::Equals:
							*operands.top().memory = operandValue(right);
							break;
						case Operator::Exclamation:
							operandValue(right) = factorial(operandValue(right));
							operands.push(right);
							break;
						case Operator::Minus:
							if(operands.empty())
							{
								operandValue(right) *= -1;
								operands.push(right);
							}
							else
								operandValue(operands.top()) -= operandValue(right);
							break;
						case Operator::Percent:
							operandValue(operands.top()) = std::fmod(operandValue(operands.top()), operandValue(right));
							break;
						case Operator::Plus:
							operandValue(operands.top()) += operandValue(right);
							break;
						case Operator::Slash:
							operandValue(operands.top()) /= operandValue(right);
							break;
						default: assert(false); break;
					}
				}
				break;
		}						
	}

	return operands.empty() ? 0 : operandValue(operands.top());
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

const Value& Interpreter::operandValue(const Token& operand)
{
	return operand.type == Token::Type::Memory ? *operand.memory : operand.value;
}

Value& Interpreter::operandValue(Token& operand)
{
	return operand.type == Token::Type::Memory ? *operand.memory : operand.value;
}

void Interpreter::parse(std::istream& is, std::vector<Token>& expression)
{
	char c;
	while(is && (c = is.get()) != '\n')
	{
		Token token{Token::Type::Operator, {}};

		switch(c)
		{
			case '*': token.op = Operator::Asterix; break;
			case '^': token.op = Operator::Caret; break;
			case '=': token.op = Operator::Equals; break;
			case '!': token.op = Operator::Exclamation; break;
			case '(': token.op = Operator::LeftParenthesis; break;
			case '%': token.op = Operator::Percent; break;
			case '+': token.op = Operator::Plus; break;
			case ')': token.op = Operator::RightParenthesis; break;
			case '/': token.op = Operator::Slash; break;
					  // Only extract minus as an operator if it is used for subtraction
			case '-':
					  if(expression.empty() || expression.back().type == Token::Type::Value || expression.back().type == Token::Type::Memory || expression.back().op == Operator::RightParenthesis)
						  token.op = Operator::Minus;
					  break;
					  // Ignore spaces
			case ' ':
			case '\t':
					  continue;
			default:
					  // Token is a name
					  if(std::isalpha(c))
					  {
						  std::string name;

						  // Get name
						  name.push_back(c);
						  do
							  name.push_back(is.get());
						  while(std::isalnum(is.peek()) || is.peek() == '_');

						  token.type = Token::Type::Memory;
						  token.memory = &memory[name];
					  }
					  else
					  {
						  is.unget();

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
