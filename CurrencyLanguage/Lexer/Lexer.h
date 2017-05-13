#pragma once

#include <string>
#include <cctype>
#include "Token.h"
#include "Exceptions.h"

class Lexer {
	std::string input_;
	std::string::iterator position_;

	Token token_;

	void SkipWhitespace();
	Token TryEOF();
	Token TryIdentifier();
	Token TryNumber();
	Token TrySingleOperator();
	Token TryDoubleOperator();
	Token TryString();

public:
	Lexer(std::string input);
	Token ReadToken();
	Token GetToken();
};
