#include "Token.hpp"
#include <iterator>
#include <sstream>

long double interpret(std::istream& is);

int main(int argc, char* argv[])
{
	switch(argc)
	{
		case 1:
			while(true)
			{
				std::cout << interpret(std::cin) << std::endl;
				std::cin.ignore();
			};
			break;
		case 2:
			{
				std::istringstream iss{argv[1]};
				std::cout << interpret(iss) << std::endl;
			}
			break;
		default:
			std::cout << "Usage: smi or smi <expression>" << std::endl;
			break;
	}
}	

long double interpret(std::istream& is)
{
	std::vector<Token> tokens{std::istream_iterator<Token>{is}, std::istream_iterator<Token>{}};
	postfix(tokens);
	return evaluate(tokens);
}
