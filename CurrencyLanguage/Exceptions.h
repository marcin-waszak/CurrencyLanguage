#pragma once

#include <exception>

class ReachException : public std::exception {
	const char* what() const throw() override;
};

class TokenTypeException : public std::exception {
	const char* what() const throw() override;
};
