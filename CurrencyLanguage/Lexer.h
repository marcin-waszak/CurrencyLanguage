#pragma once

#include <string>
#include <cctype>
#include "Token.h"


class Lexer {
	std::string input_;
	std::string::iterator position_;
	std::string current_token_;

public:
	Lexer(std::string input);

	Token GetToken();

	void SkipWhitespace();
	bool TryEOF();
	EToken TryIdentifier();
	EToken TrySingleOperator();
	EToken TryDoubleOperator();
};