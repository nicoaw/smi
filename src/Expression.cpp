#include "Expression.hpp"
#include <cassert>
#include <cmath>
#include <stack>

long double evaluate(const Expression& postfixExpression)
{
	std::stack<long double> operands; 
	auto popOperand = [&operands]()
	{
		long double temporary{operands.top()};
		operands.pop();
		return temporary;
	};

	auto factorial = [](unsigned long long n)
	{
		unsigned long long result{n};
		while(n > 1)
			result *= --n;
		return result;
	};

	for(const Token& token : postfixExpression)
	{
		switch(token.type)
		{
			case Token::Type::Operand:
				operands.push(token.num);
				break;
			case Token::Type::Operator:
				{
					long double rhs{popOperand()};
					switch(token.op)
					{
						case Operator::Asterix: operands.top() *= rhs; break;
						case Operator::Caret: operands.top() = pow(operands.top(), rhs); break;
						case Operator::Exclamation: operands.push(factorial(rhs)); break;
						case Operator::Minus: if(operands.empty()) operands.push(-rhs); else operands.top() -= rhs; break;
						case Operator::Percent: operands.top() = fmod(operands.top(), rhs); break;
						case Operator::Plus: operands.top() += rhs; break;
						case Operator::Slash: operands.top() /= rhs; break;
						default: assert(false); break;
					}
				}
				break;
		}						
	}

	return postfixExpression.empty() ? 0 : operands.top();	
}

std::istream& operator>>(std::istream& is, Expression& expression)
{
	char c;
	while(is && (c = is.get()) != '\n')
	{
		Token token{Token::Type::Operator, {}};
		switch(c)
		{
			case '*': token.op = Operator::Asterix; break;
			case '^': token.op = Operator::Caret; break;
			case '!': token.op = Operator::Exclamation; break;
			case '(': token.op = Operator::LeftParenthesis; break;
			case '%': token.op = Operator::Percent; break;
			case '+': token.op = Operator::Plus; break;
			case ')': token.op = Operator::RightParenthesis; break;
			case '/': token.op = Operator::Slash; break;
					  // Only extract minus as an operator if it is used for subtraction
			case '-': if(expression.empty() || expression.back().type == Token::Type::Operand || expression.back().op == Operator::RightParenthesis) { token.op = Operator::Minus; break; }
			default:
						  is.unget();
						  // Token is a number
						  if(is >> token.num) token.type = Token::Type::Operand;
						  break;
		}

		if(is) expression.push_back(token);

		// Skip all white space except new lines
		while(is.peek() == ' ' || is.peek() == '\t')
			is.ignore();
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Expression& expression)
{
	for(const Token& token : expression)
	{
		switch(token.type)
		{
			// Output number
			case Token::Type::Operand:
				os << token.num;
				break;
				// Output operator
			case Token::Type::Operator:
				switch(token.op)
				{
					case Operator::Asterix: os.put('*'); break;
					case Operator::Caret: os.put('^'); break;
					case Operator::Exclamation: os.put('!'); break;
					case Operator::LeftParenthesis: os.put('('); break;
					case Operator::Minus: os.put('-'); break;
					case Operator::Percent: os.put('%'); break;
					case Operator::Plus: os.put('+'); break;
					case Operator::RightParenthesis: os.put(')'); break;
					case Operator::Slash: os.put('/'); break;
				}
				break;
		}
	}

	return os;
}

void postfix(Expression& expression)
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
			case Token::Type::Operand:
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
					default://case Operator::LeftParenthesis:
						// Push operators untill there is no more, opertor is a left parenthesis, or operator is lower precedence compared to the current token
						while(!operators.empty() && operators.top().op != Operator::LeftParenthesis && token.op >= operators.top().op)
							*(result++) = popOperator();
					//default:
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
