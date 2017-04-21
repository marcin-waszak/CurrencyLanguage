#pragma once

#include <string>
#include <cctype>
#include "Token.h"
#include "Exceptions.h"

class Lexer {
	std::string input_;
	std::string::iterator position_;
	std::string current_token_;

	void SkipWhitespace();
	bool TryEOF();
	Token::Type TryIdentifier();
	Token::Type TrySingleOperator();
	Token::Type TryDoubleOperator();

public:
	Lexer(std::string input);
	Token GetToken();
};
