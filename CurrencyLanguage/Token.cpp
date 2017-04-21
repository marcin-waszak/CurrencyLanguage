#include "Token.h"

std::map<std::string, Token::Type> Token::keywords_map_ = {
	{ "true", Token::Type::TRUE },
	{ "false", Token::Type::FALSE },
	{ "if", Type::IF },
	{ "else", Token::Type::ELSE },
	{ "while", Token::Type::WHILE },
	{ "currency", Token::Type::CURRENCY },
	{ "exrate", Token::Type::EXRATE },
	{ "var", Token::Type::VAR },
	{ "function", Token::Type::FUNCTION },
	{ "return", Token::Type::RETURN },
	{ "print", Token::Type::PRINT },
	{ "as", Token::Type::AS },
};

std::map<char, Token::Type> Token::short_operator_map_ = {
	{ '{', Token::Type::BRACKET_OPEN },
	{ '}', Token::Type::BRACKET_CLOSE },
	{ '(', Token::Type::PARENTHESIS_OPEN },
	{ ')', Token::Type::PARENTHESIS_CLOSE },
	{ ',', Token::Type::COMMA },
	{ ';', Token::Type::SEMICOLON },
	{ '|', Token::Type::OR },
	{ '&', Token::Type::AND },
	{ '+', Token::Type::PLUS },
	{ '-', Token::Type::MINUS },
	{ '*', Token::Type::MULTIPLY },
	{ '/', Token::Type::DIVIDE },
};

Token::Token(Token::Type type, std::string text) {
}

Token::Type Token::GetType() {
	return type_;
}

const std::map<std::string, Token::Type>& Token::GetKeywordsMap() {
	return keywords_map_;
}

const std::map<char, Token::Type>& Token::GetShortOpMap() {
	return short_operator_map_;
}
