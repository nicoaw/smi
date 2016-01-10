#include "Interpreter.hpp"
#include <cmath>
#include <sstream>

int factorial(int n);

Interpreter::Interpreter()
{
	storage.emplace();
}

double Interpreter::exponent(std::istream& is)
{
	double left = operand(is);

	while(true)
		switch(is.peek())
		{
			case '^':
				is.get();
				left = std::pow(left, operand(is));
				break;
			case '!':
				is.get();
				left = factorial(left);
				break;
			default:
				return left;
		}
}

double Interpreter::factor(std::istream& is)
{
	double left = exponent(is);

	while(true)
		switch(is.peek())
		{
			case '*':
				is.get();
				left *= exponent(is);
				break;
			case '/':
				is.get();
				left /= exponent(is);
				break;
			default:
				return left;
		}

	throw 1;
}

double Interpreter::interpret(std::istream& is)
{
	double value = term(is);
	is.ignore();
	return value;
}

double Interpreter::operand(std::istream& is)
{
	switch(is.peek())
	{
		case '-':
			is.get();
			return -operand(is);
		case '(':
			{
				is.get();

				double value = term(is);
				if(is.get() == ')')
					return value;

				break;
			}
		default:
			{
				std::string name;
				while(std::isalpha(is.peek()))
					name += (char) is.get();
				
				if(!name.empty())
				{
					double& value = storage.top()[name];

					// Global variable assignment
					if(is.peek() == '=')
					{
						is.get();
						value = term(is);
					}

					return value;
				}
				else
				{
					double value;

					if(is >> value)
						return value;
				}

				break;
			}
	}

	throw 1;
}

void Interpreter::setGlobalValue(const std::string& name, double value)
{
	storage.top()[name] = value;
}

double Interpreter::term(std::istream& is)
{
	double left = factor(is);

	while(true)
		switch(is.peek())
		{
			case '+':
				is.get();
				left += factor(is);
				break;
			case '-':
				is.get();
				left -= factor(is);
				break;
			default:
				return left;
		}

	throw 1;
}

double testInterpreter(Interpreter& interp, const std::string& expression);

int main(int, char**)
{
	Interpreter interp;
	interp.setGlobalValue("pi", M_PI);
	interp.setGlobalValue("e", M_E);

	double h;

	std::pair<double, std::string> tests[] =
	{
		{2+3, "2+3"},
		{-4*5, "-4*5"},
		{2+-4, "2+-4"},
		{5*3+4, "5*3+4"},
		{5+3*4, "5+3*4"},
		{(5+3)*4, "(5+3)*4"},
		{-(5+3)*4, "-(5+3)*4"},
		{5*-(6*(9+3)+4), "5*-(6*(9+3)+4)"},
		{6-8/3e4, "6-8/3e4"},
		{3*std::pow(4,5)-6, "3*4^5-6"},
		{7*factorial(6)+3, "7*6!+3"},
		{factorial(2*3+3), "(2*3+3)!"},
		{std::pow(4+7*8,9+4), "(4+7*8)^(9+4)"},
		{std::pow(3, std::pow(2, 4)), "3^(2^4)"},
		{M_PI*(3-9), "pi*(3-9)"},
		{(-M_E+4)*8, "(-e+4)*8"},
		{h=99, "h=99"},
		{h*8+3, "h*8+3"},
		{h=-(8+M_PI)/4, "h=-(8+pi)/4"},
		{h, "h"},
	};

	std::size_t numTests = 0, numTestPassed = 0;

	for(const auto& test: tests)
	{
		double cpp = test.first, smi = testInterpreter(interp, test.second);
	
		std::cout
			<< test.second << std::endl
			<< "  C++ " << cpp << std::endl
			<< "  smi " << smi << std::endl
			<< "  " << (cpp == smi ? "PASSED" : "MAYBE FAILED")  << std::endl
			<< std::endl
			;

		++numTests;
		numTestPassed += (cpp == smi ? 1 : 0);
	}

	std::cout << "Tests " << numTests << ", passed " << numTestPassed << std::endl;

/*
	while(true)
	{
		std::cout << ">> ";
		std::cout.flush();
		std::cout << interp.interpret(std::cin) << std::endl;
	}
	*/

	return 0;
}

int factorial(int n)
{
	if(n < 0)
		throw 1;
	else if(n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

double testInterpreter(Interpreter& interp, const std::string& expression)
{
	std::istringstream iss{expression};
	return interp.interpret(iss);
}
