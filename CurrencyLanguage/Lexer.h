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
	Token::Type TryNumber();
	Token::Type TrySingleOperator();
	Token::Type TryDoubleOperator();
	Token::Type TryString();

public:
	Lexer(std::string input);
	Token GetToken();
};
