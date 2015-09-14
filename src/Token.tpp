#include "Token.hpp"
#include <stack>

	template<typename InputIterator, typename OutputIterator>
void postfix(InputIterator first, InputIterator last, OutputIterator last)
{
	std::stack<Token> operators;


