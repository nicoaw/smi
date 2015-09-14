#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "Token.hpp"
#include <iostream>
#include <vector>

using Expression = std::vector<Token>;

long double evaluate(const Expression& postfixExpression); // Must be in postifx
std::istream& operator>>(std::istream& is, Expression& expression);
std::ostream& operator<<(std::ostream& os, const Expression& expression);
void postfix(Expression& expression); // Converts an expression to postfix

#endif /* EXPRESSION_HPP */
