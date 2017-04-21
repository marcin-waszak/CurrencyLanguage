
#include "Lexer.h"

int main() {
	const char* PROGRAM = R"(while{elseif<=while)";

	Lexer lexer(PROGRAM);
	while (lexer.GetToken().GetType() != Token::Type::END_OF_FILE);

	return 0;
}
