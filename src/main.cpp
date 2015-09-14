#include "Expression.hpp"
#include <iterator>
#include <limits>
#include <sstream>

void interpret(std::istream& is);

int main(int argc, char* argv[])
{
	if(argc == 1)
		while(true)
			interpret(std::cin);
	else
		std::cout << "Usage: " << argv[0] << std::endl;
}	

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
