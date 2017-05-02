#include "Lexer.h"

Lexer::Lexer(std::string input)
	: input_(input), position_(input_.begin()) {

}

Token Lexer::GetToken() {
	Token token;

	SkipWhitespace();

	token = TryEOF();
	if (token.GetType())
		return token;

	token = TryIdentifier();
	if (token.GetType())
		return token;

	token = TryNumber();
	if (token.GetType())
		return token;

	token = TrySingleOperator();
	if (token.GetType())
		return token;

	token = TryDoubleOperator();
	if (token.GetType())
		return token;

	token = TryString();
	if (token.GetType())
		return token;

	throw ReachException();
}

void Lexer::SkipWhitespace() {
	while (position_ != input_.end() && std::isspace(*position_))
		++position_;
}

Token Lexer::TryEOF() {
	if (position_ == input_.end())
		return Token(Token::Type::END_OF_FILE);
	else
		return Token(Token::Type::UNKNOWN);
}

Token Lexer::TryIdentifier() {
	auto start = position_;

	if (std::isdigit(*position_))
		return Token(Token::Type::UNKNOWN);

	while (std::isalnum(*position_) || *position_ == '_') {
		++position_;

		if (position_ == input_.end())
			break;
	}

	auto result = std::string(start, position_);

	if (result.size() < 1)
		return Token(Token::Type::UNKNOWN);

	auto keywords = Token::GetKeywordsMap();
	auto found = keywords.find(result);
	if (found == keywords.end())
		return Token(Token::Type::IDENTIFIER, result);
	else
		return Token(found->second);

	throw ReachException();
}

Token Lexer::TryNumber() {
	auto start = position_;

	if (!std::isdigit(*position_))
		return Token(Token::Type::UNKNOWN);

	while (std::isdigit(*position_)) {
		++position_;

		if (position_ == input_.end())
			return Token(Token::Type::END_OF_FILE);
	}

	if (*position_ == '.') {
		++position_;

		if (!std::isdigit(*position_))
			return Token(Token::Type::UNKNOWN);

		while (std::isdigit(*position_)) {
			++position_;

			if (position_ == input_.end())
				break;
		}
	}

	auto result = std::string(start, position_);
	double number = atof(result.c_str());
	return Token(Token::Type::NUMBER, number);
}

Token Lexer::TrySingleOperator() {
	auto token_map = Token::GetShortOpMap();
	auto found = token_map.find(*position_);
	if (found != token_map.end()) {
		++position_;
		return Token(found->second);
	}

	return Token(Token::Type::UNKNOWN);
}

Token Lexer::TryDoubleOperator() {
	switch (*position_) {
	case '<':
		++position_;
		if (position_ != input_.end() && *position_ == '=') {
			++position_;
			return Token(Token::Type::LESSEQ);
		}

		return Token(Token::Type::LESS);

	case '>':
		++position_;
		if (position_ != input_.end() && *position_ == '=') {
			++position_;
			return Token(Token::Type::GREATEREQ);
		}

		return Token(Token::Type::GREATER);

	case '=':
		++position_;
		if (position_ != input_.end() && *position_ == '=') {
			++position_;
			return Token(Token::Type::EQUAL);
		}

		return Token(Token::Type::ASSIGN);

	case '!':
		++position_;
		if (position_ != input_.end() && *position_ == '=') {
			++position_;
			return Token(Token::Type::UNEQUAL);
		}

		return Token(Token::Type::INVERT);
	}

	return Token(Token::Type::UNKNOWN);
}

Token Lexer::TryString() {
	auto start = position_;

	if (*position_ != '\"')
		return Token(Token::Type::UNKNOWN);

	++position_;

	while (std::isprint(*position_)) {
		++position_;

		if (position_ == input_.end())
			return Token(Token::Type::END_OF_FILE);

		if (*position_ == '\"') {
			++position_;
			auto result = std::string(start + 1, position_ - 1);
			return Token(Token::Type::STRING, result);
		}
	}

	return Token(Token::Type::UNKNOWN);
}
