#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "Token.hpp"
#include <iostream>
#include <map>
#include <vector>

class Interpreter
{
	public:
		Value interpret(std::istream& is);
	private:
		Value evaluate(const std::vector<Token>& postfixExpression);
		static unsigned long long factorial(unsigned long long n);
		static const Value& operandValue(const Token& operand);
		static Value& operandValue(Token& operand);
		void parse(std::istream& is, std::vector<Token>& expression);
		static void postfix(std::vector<Token>& expression);
		std::map<std::string, Value> memory;
};

#endif /* INTERPRETER_HPP */
