#include "Token.h"

std::map<std::string, EToken> Token::keywords_map_ = {
	{ "true", EToken::TRUE },
	{ "false", EToken::FALSE },
	{ "if", EToken::IF },
	{ "else", EToken::ELSE },
	{ "while", EToken::WHILE },
	{ "currency", EToken::CURRENCY },
	{ "exrate", EToken::EXRATE },
	{ "var", EToken::VAR },
	{ "function", EToken::FUNCTION },
	{ "return", EToken::RETURN },
	{ "print", EToken::PRINT },
	{ "as", EToken::AS },
};

std::map<char, EToken> Token::short_operator_map_ = {
	{ '{', EToken::BRACKET_OPEN },
	{ '}', EToken::BRACKET_CLOSE },
	{ '(', EToken::PARENTHESIS_OPEN },
	{ ')', EToken::PARENTHESIS_CLOSE },
	{ ',', EToken::COMMA },
	{ ';', EToken::SEMICOLON },
	{ '|', EToken::OR },
	{ '&', EToken::AND },
	{ '+', EToken::PLUS },
	{ '-', EToken::MINUS },
	{ '*', EToken::MULTIPLY },
	{ '/', EToken::DIVIDE },
};

Token::Token(EToken type, std::string text) {
}

EToken Token::GetType() {
	return type_;
}

const std::map<std::string, EToken>& Token::GetKeywordsMap() {
	return keywords_map_;
}

const std::map<char, EToken>& Token::GetShortOpMap() {
	return short_operator_map_;
}
