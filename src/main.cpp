#include "Interpreter.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	Interpreter interpreter;

	try
	{
		cout << interpreter.interpret(argv[1]) << endl;
	}
	catch(exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}
