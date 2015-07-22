#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "Token.hpp"
#include <iterator>
#include <sstream>

class Interpreter
{
	public:
		Real interpret(const std::string& expression);

	private:
		Real exp(bool next);

		Real expr(bool next);

		Real prim(bool next);

		Real term(bool next);

		std::istringstream iss;	
		std::istream_iterator<Token> it;
};

#endif /* INTERPRETER_HPP */
