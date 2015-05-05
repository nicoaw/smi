#include "Interpreter.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
	cout << "ans = " << interpret(argv[1]) << endl;
	}
	catch(int err)
	{
		cout << "err: " << err << endl;
	}
	return 0;
}
