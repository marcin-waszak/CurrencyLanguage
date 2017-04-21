#pragma once

#include <exception>

class ReachException : public std::exception {
	virtual const char* what() const throw();
} reach_exception;
