#include "Interpreter.hpp"
#include <iostream>

using namespace std;

bool promptInput(string& input);

int main(int argc, char* argv[])
{
	Interpreter interpreter;
	interpreter.setValue("pi", 3.14159f);

	if(argc == 1)
	{
		string input;
		while(promptInput(input))
		{
			Real ans = interpreter.interpret(input);
			interpreter.setValue("ans", ans);
			cout << "ans = " << ans << endl;
		}
	}	
	if(argc == 2)
	{
		try
		{
			cout << interpreter.interpret(argv[1]) << endl;
		}
		catch(exception& e)
		{
			cout << "Error: " << e.what() << endl;
		}
	}
	else
		cout << "You must supply an expression (i.e. smi 2+2)" << endl;

	return 0;
}

bool promptInput(string& input)
{
	cout << ">> ";
	return (bool) getline(cin, input);
}
