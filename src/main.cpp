#include "Interpreter.hpp"
#include <fstream>
#include <iomanip>
#include <iterator>
#include <limits>
#include <sstream>

int main(int, char**)
{
	Interpreter interpreter;

	while(true)
	{
		std::cout << ">> ";
		std::cout << interpreter.interpret(std::cin) << std::endl;
	}
}	
/*
void interpret(std::istream& is)
{
	std::cout << ">> ";
	Expression expression;
	is >> expression;

	if(!is)
	{
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	if(!expression.empty())
	{
		postfix(expression);
		std::cout << evaluate(expression) << std::endl;
	}
}
*/
