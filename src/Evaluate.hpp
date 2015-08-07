#ifndef EVALUATE_HPP
#define EVALUATE_HPP

#include "Token.hpp"
#include <map>
#include <vector>

Real evaluate(std::map<std::string, Real>& memory, const std::vector<Token>& tokens);

#endif /* EVALUATE_HPP */
