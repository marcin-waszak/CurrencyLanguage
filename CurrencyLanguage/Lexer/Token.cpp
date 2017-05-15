#include "Token.h"

const double Token::DOUBLE_EPSILON = 1E-10;

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

Token::Token()
	: type_(Token::Type::UNKNOWN), number_(0.0) {

}

Token::Token(Token::Type type)
	: type_(type), number_(0.0) {
	if (type_ == Token::Type::IDENTIFIER
		|| type_ == Token::Type::NUMBER
		|| type_ == Token::Type::STRING)
		throw TokenTypeException();
}

Token::Token(Token::Type type, std::string text)
	: type_(type), number_(0.0) {
	switch (type_) {
	case Token::Type::IDENTIFIER:
		identifier_ = text;
		return;
	case Token::Type::STRING:
		string_ = text;
		return;
	default:
		throw TokenTypeException();
	}
}

Token::Token(Token::Type type, double number)
	: type_(type), number_(number) {
	if (type_ != Token::Type::NUMBER)
		throw TokenTypeException();
}

bool Token::operator==(const Token &rhs) const {
	return type_ == rhs.type_
		&& identifier_ == rhs.identifier_
		&& string_ == rhs.string_
		&& fabs(number_ - rhs.number_) < DOUBLE_EPSILON;
}

bool Token::operator!=(const Token &rhs) const {
	return !(*this == rhs);
}

Token::Type Token::GetType() {
	return type_;
}

std::string Token::GetIdentifier() {
	if (type_ != Token::Type::IDENTIFIER)
		throw TokenTypeException();

	return identifier_;
}

std::string Token::GetString() {
	if (type_ != Token::Type::STRING)
		throw TokenTypeException();

	return string_;
}

double Token::GetNumber() {
	if (type_ != Token::Type::NUMBER)
		throw TokenTypeException();

	return number_;
}

const std::map<std::string, Token::Type>& Token::GetKeywordsMap() {
	return keywords_map_;
}

const std::map<char, Token::Type>& Token::GetShortOpMap() {
	return short_operator_map_;
}
