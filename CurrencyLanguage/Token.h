#pragma once

#include <string>
#include <map>

#include "Exceptions.h"

class Token {
public:
	enum Type {
		UNKNOWN = 0,

		BRACKET_OPEN,
		BRACKET_CLOSE,
		PARENTHESIS_OPEN,
		PARENTHESIS_CLOSE,
		COMMA,
		SEMICOLON,

		TRUE,
		FALSE,
		IF,
		ELSE,
		WHILE,
		CURRENCY,
		EXRATE,
		VAR,
		FUNCTION,
		RETURN,
		PRINT,

		AS,
		ASSIGN,
		OR,
		AND,
		EQUAL,
		UNEQUAL,
		LESS,
		LESSEQ,
		GREATER,
		GREATEREQ,
		PLUS,
		MINUS,
		MULTIPLY,
		DIVIDE,
		INVERT,

		IDENTIFIER,
		NUMBER,
		STRING,

		END_OF_FILE,
	};

	Token();
	Token(Type type);
	Token(Type type, std::string text);
	Token(Type type, double number);
	Type GetType();
	static const std::map<std::string, Type>& GetKeywordsMap();
	static const std::map<char, Type>& GetShortOpMap();

private:
	Type type_;
	std::string identifier_;
	std::string string_;
	double number_;

	static std::map<std::string, Type> keywords_map_;
	static std::map<char, Type> short_operator_map_;
};
