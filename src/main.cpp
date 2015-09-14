#include "Token.hpp"
#include <iterator>
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
	std::vector<Token> tokens{std::istream_iterator<Token>{is}, std::istream_iterator<Token>{}};
	is.clear();

	if(!tokens.empty())
	{
		postfix(tokens);
		std::cout << evaluate(tokens) << std::endl;
	}
}
