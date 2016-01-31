#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

class Interpreter
{
	public:
		Interpreter();
		double interpret(std::istream& is);
		void setGlobalValue(const std::string& name, double value);
	private:
		double exponent(std::istream& is);
		double factor(std::istream& is);
		double operand(std::istream& is);
		double term(std::istream& is);
		std::unordered_map<std::string, double> storage;
};

#endif /* INTERPRETER_HPP */
