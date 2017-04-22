#include "Lexer.h"
#include <cstdio>

int main() {
	const char* PROGRAM = R"(while{0.45"Test Test test"elseif<=while<)";

	Lexer lexer(PROGRAM);


	while (1) {
		Token::Type type = lexer.GetToken().GetType();

		printf("%d\n", type);

		if (type == Token::Type::END_OF_FILE)
			break;
	}

	return 0;
}
