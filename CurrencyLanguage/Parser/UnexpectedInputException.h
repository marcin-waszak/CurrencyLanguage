#pragma once

#include <exception>
#include <sstream>
#include "../Lexer/Token.h"

class UnexpectedInputException : public std::exception {
public:
    //UnexpectedInputException(unsigned int line, const Token& token);
	UnexpectedInputException();

	const char* what() const noexcept override;

private:
    std::string message_;
};
