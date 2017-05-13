#define BOOST_TEST_MODULE LexerTest

#include <boost/test/unit_test.hpp>
#include <vector>
#include "Lexer.h"

bool CompareReference(std::vector<Token> ref_tokens, Lexer& lexer) {
	std::vector<Token> tokens;

	while (1) {
		auto token = lexer.ReadToken();
		tokens.push_back(token);

		if (token.GetType() == Token::Type::END_OF_FILE)
			break;
	}

	if (ref_tokens.size() != tokens.size())
		return false;

	for (size_t i = 0; i < tokens.size(); ++i)
		if (ref_tokens[i] != tokens[i])
			return false;

	return true;
}

BOOST_AUTO_TEST_CASE(BracketOpenToken)
{
	const char* program = R"({)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::BRACKET_OPEN),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(BracketCloseToken)
{
	const char* program = R"(})";
	std::vector<Token> ref_tokens{
		Token(Token::Type::BRACKET_CLOSE),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(ParenthesisCloseToken)
{
	const char* program = R"())";
	std::vector<Token> ref_tokens{
		Token(Token::Type::PARENTHESIS_CLOSE),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(ParenthesisOpenToken)
{
	const char* program = R"(()";
	std::vector<Token> ref_tokens{
		Token(Token::Type::PARENTHESIS_OPEN),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(CommaToken)
{
	const char* program = R"(,)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::COMMA),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(SemicolonToken)
{
	const char* program = R"(;)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::SEMICOLON),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(TrueToken)
{
	const char* program = R"(true)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::TRUE),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(FalseToken)
{
	const char* program = R"(false)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::FALSE),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(IfToken)
{
	const char* program = R"(if)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::IF),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(ElseToken)
{
	const char* program = R"(else)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::ELSE),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(WhileToken)
{
	const char* program = R"(while)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::WHILE),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(CurrencyToken)
{
	const char* program = R"(currency)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::CURRENCY),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(ExrateToken)
{
	const char* program = R"(exrate)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::EXRATE),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(VarToken)
{
	const char* program = R"(var)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::VAR),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(FunctionToken)
{
	const char* program = R"(function)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::FUNCTION),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(ReturnToken)
{
	const char* program = R"(return)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::RETURN),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(PrintToken)
{
	const char* program = R"(print)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::PRINT),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(AsToken)
{
	const char* program = R"(as)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::AS),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(AssignToken)
{
	const char* program = R"(=)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::ASSIGN),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(OrToken)
{
	const char* program = R"(|)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::OR),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(AndToken)
{
	const char* program = R"(&)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::AND),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(EqualToken)
{
	const char* program = R"(==)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::EQUAL),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(UnequalToken)
{
	const char* program = R"(!=)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::UNEQUAL),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(LessToken)
{
	const char* program = R"(<)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::LESS),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(LessEqualToken)
{
	const char* program = R"(<=)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::LESSEQ),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(GreaterToken)
{
	const char* program = R"(>)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::GREATER),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(GreaterEqualToken)
{
	const char* program = R"(>=)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::GREATEREQ),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(PlusToken)
{
	const char* program = R"(+)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::PLUS),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(MinusToken)
{
	const char* program = R"(-)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::MINUS),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(MultiplyToken)
{
	const char* program = R"(*)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::MULTIPLY),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(DivideToken)
{
	const char* program = R"(/)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::DIVIDE),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(InvertToken)
{
	const char* program = R"(!)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::INVERT),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(IdentifierToken)
{
	const char* program = R"(Identifier123)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::IDENTIFIER, "Identifier123"),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(NumberToken)
{
	const char* program = R"(3.14159265359)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::NUMBER, 3.14159265359),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(StringToken)
{
	const char* program = R"("Test string 123")";
	std::vector<Token> ref_tokens{
		Token(Token::Type::STRING, "Test string 123"),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(LongTest_1)
{
	const char* program = R"(while{0.45"Test Test test"elseif<=while<)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::WHILE),
		Token(Token::Type::BRACKET_OPEN),
		Token(Token::Type::NUMBER, 0.45),
		Token(Token::Type::STRING, "Test Test test"),
		Token(Token::Type::IDENTIFIER, "elseif"),
		Token(Token::Type::LESSEQ),
		Token(Token::Type::WHILE),
		Token(Token::Type::LESS),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(LongTest_2)
{
	const char* program = R"(
		     			     
						                 
	while{
    0.45    "Test Test test"
    elseif	 <=	while
	<
	)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::WHILE),
		Token(Token::Type::BRACKET_OPEN),
		Token(Token::Type::NUMBER, 0.45),
		Token(Token::Type::STRING, "Test Test test"),
		Token(Token::Type::IDENTIFIER, "elseif"),
		Token(Token::Type::LESSEQ),
		Token(Token::Type::WHILE),
		Token(Token::Type::LESS),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}

BOOST_AUTO_TEST_CASE(LongTest_3)
{
	const char* program = R"(
while
{
0.45
"Test Test test"
elseif
<=
while
<
)";
	std::vector<Token> ref_tokens{
		Token(Token::Type::WHILE),
		Token(Token::Type::BRACKET_OPEN),
		Token(Token::Type::NUMBER, 0.45),
		Token(Token::Type::STRING, "Test Test test"),
		Token(Token::Type::IDENTIFIER, "elseif"),
		Token(Token::Type::LESSEQ),
		Token(Token::Type::WHILE),
		Token(Token::Type::LESS),
		Token(Token::Type::END_OF_FILE)
	};

	Lexer lexer(program);
	BOOST_CHECK(CompareReference(ref_tokens, lexer));
}
