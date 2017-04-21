#include "Lexer.h"

Lexer::Lexer(std::string input)
	: input_(input), position_(input_.begin()) {

}

Token Lexer::GetToken() {
	SkipWhitespace();

	if(TryEOF())
		return Token(Token::Type::END_OF_FILE, "");

	Token::Type token;

	if (token = TryIdentifier())
		return token;

	if (token = TrySingleOperator())
		return token;

	if (token = TryDoubleOperator())
		return token;

	throw reach_exception;
}

void Lexer::SkipWhitespace() {
	while (position_ != input_.end() && std::isspace(*position_))
		++position_;
}

bool Lexer::TryEOF() {
	return position_ == input_.end();
}

Token::Type Lexer::TryIdentifier() {
	auto start = position_;

	if (std::isdigit(*position_))
		return Token::Type::UNKNOWN;

	while (std::isalnum(*position_) || *position_ == '_') {
		++position_;

		if (position_ == input_.end())
			break;
	}

	auto result = std::string(start, position_);

	if (result.size() < 1)
		return Token::Type::UNKNOWN;

	current_token_ = result;

	auto token_map = Token::GetKeywordsMap();
	auto found = token_map.find(result);
	if (found == token_map.end())
		return Token::Type::IDENTIFIER;
	else
		return found->second;

	throw reach_exception;
}

Token::Type Lexer::TrySingleOperator() {
	auto token_map = Token::GetShortOpMap();
	auto found = token_map.find(*position_);
	if (found != token_map.end()) {
		++position_;
		return found->second;
	}

	return Token::Type::UNKNOWN;
}

Token::Type Lexer::TryDoubleOperator() {
	switch (*position_) {
	case '<':
		++position_;
		if (*position_ == '=') {
			++position_;
			return Token::Type::LESSEQ;
		}

		return Token::Type::LESS;

	case '>':
		++position_;
		if (*position_ == '=') {
			++position_;
			return Token::Type::GREATEREQ;
		}

		return Token::Type::GREATER;

	case '=':
		++position_;
		if (*position_ == '=') {
			++position_;
			return Token::Type::EQUAL;
		}

		return Token::Type::ASSIGN;

	case '!':
		++position_;
		if (*position_ == '=') {
			++position_;
			return Token::Type::UNEQUAL;
		}

		return Token::Type::INVERT;
	}

	return Token::Type::UNKNOWN;
}
