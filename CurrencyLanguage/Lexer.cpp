#include "Lexer.h"

Lexer::Lexer(std::string input)
	: input_(input), position_(input_.begin()) {

}

Token Lexer::GetToken() {
	SkipWhitespace();

	if(TryEOF())
		return Token(EToken::END_OF_FILE, "");

	EToken token;

	if (token = TryIdentifier())
		return token;

	if (token = TrySingleOperator())
		return token;

	if (token = TryDoubleOperator())
		return token;

	throw "Should never reach here!";
}

void Lexer::SkipWhitespace() {
	while (position_ != input_.end() && std::isspace(*position_))
		++position_;
}

bool Lexer::TryEOF() {
	return position_ == input_.end();
}

EToken Lexer::TryIdentifier() {
	auto start = position_;

	if (std::isdigit(*position_))
		return EToken::UNKNOWN;

	while (std::isalnum(*position_) || *position_ == '_') {
		++position_;

		if (position_ == input_.end())
			break;
	}

	auto result = std::string(start, position_);

	if (result.size() < 1)
		return EToken::UNKNOWN;

	current_token_ = result;

	auto token_map = Token::GetKeywordsMap();
	auto found = token_map.find(result);
	if (found == token_map.end())
		return EToken::IDENTIFIER;
	else
		return found->second;

	throw "Should never reach here!";
}

EToken Lexer::TrySingleOperator() {
	auto token_map = Token::GetShortOpMap();
	auto found = token_map.find(*position_);
	if (found != token_map.end()) {
		++position_;
		return found->second;
	}

	return EToken::UNKNOWN;
}

EToken Lexer::TryDoubleOperator() {
	switch (*position_) {
	case '<':
		++position_;
		if (*position_ == '=') {
			++position_;
			return EToken::LESSEQ;
		}

		return EToken::LESS;

	case '>':
		++position_;
		if (*position_ == '=') {
			++position_;
			return EToken::GREATEREQ;
		}

		return EToken::GREATER;

	case '=':
		++position_;
		if (*position_ == '=') {
			++position_;
			return EToken::EQUAL;
		}

		return EToken::ASSIGN;

	case '!':
		++position_;
		if (*position_ == '=') {
			++position_;
			return EToken::UNEQUAL;
		}

		return EToken::INVERT;
	}
}
