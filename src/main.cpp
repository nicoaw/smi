#include "Evaluate.hpp"
#include "Form.hpp"
#include <iterator>
#include <sstream>

using namespace std;

Real interpret(map<string, Real>& memory, const string& expression);

bool promptInput(string& input);

int main(int argc, char* argv[])
{
	map<string, Real> memory
	{
		{ "pi", 3.14159f }
	};

	try
	{
		if(argc == 1)
		{
			string input;
			while(promptInput(input))
				cout << interpret(memory, input) << endl;
		}	
		if(argc == 2)
			cout << interpret(memory, argv[1]) << endl;
		else
			cout << "You must supply an expression (i.e. smi 2+2)" << endl;
	}
	catch(exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}

Real interpret(map<string, Real>& memory, const string& expression)
{
	istringstream iss{expression};
	vector<Token> tokens;
	copy(istream_iterator<Token>{iss}, istream_iterator<Token>{}, back_inserter(tokens));
	postfix(tokens);
	return evaluate(memory, tokens);
}

bool promptInput(string& input)
{
	cout << ">> ";
	return (bool) getline(cin, input);
}
