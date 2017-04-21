#pragma once

#include <string>
#include <map>

enum EToken {
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

class Token {
	EToken type_;
	std::string text_;
	static std::map<std::string, EToken> keywords_map_;
	static std::map<char, EToken> short_operator_map_;
	
public:
	Token(EToken type, std::string text = "");
	EToken GetType();
	static const std::map<std::string, EToken>& GetKeywordsMap();
	static const std::map<char, EToken>& GetShortOpMap();
};
