#include "Exceptions.h"

const char* ReachException::what() const throw() {
	return "Should never reach here!";
}
