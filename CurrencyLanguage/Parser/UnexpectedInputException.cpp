#include "UnexpectedInputException.h"

/*UnexpectedInputException::UnexpectedInputException(unsigned int line, const Token& token)
: message_("Unexpected token at line ")
{
std::stringstream ss;
ss << line << ": ";
ss << token;
message_ += ss.str();
}*/

UnexpectedInputException::UnexpectedInputException()
	: message_("Unexpected token") {

}

const char* UnexpectedInputException::what() const {
	return message_.c_str();
}
