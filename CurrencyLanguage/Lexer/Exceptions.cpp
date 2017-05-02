#include "Exceptions.h"

const char* ReachException::what() const throw() {
	return "Should never reach here!";
}

const char * TokenTypeException::what() const throw() {
	return "Bad token type! Token type and attribute mismatch.";
}
