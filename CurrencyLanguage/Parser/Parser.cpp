#include "Parser.h"

Parser::TokenPtr Parser::CheckToken(Token::Type expected) {
	TokenPtr token(new Token(lexer_.GetToken()));
	if (token->GetType() != expected)
		return nullptr;

	Advance();
	return token;
}

Parser::TokenPtr Parser::CheckToken(const std::initializer_list<Token::Type>& expected) {
	for (auto& type : expected)
		if (auto token = CheckToken(type))
			return std::move(token);

	return nullptr;
}

Parser::TokenPtr Parser::RequireToken(Token::Type expected)
{
	TokenPtr token = CheckToken(expected);

	if (token)
		return token;

	throw UnexpectedInputException();
}

Token& Parser::GetToken() {
	return lexer_.GetToken();
}

Token& Parser::Advance() {
	return lexer_.ReadToken();
}

Parser::Parser(Lexer& lexer) : lexer_(lexer) {

}

Parser::NodePtr Parser::Parse() {
	Advance();
	return ReadMain();
}

Parser::NodePtr Parser::ReadMain() {
	std::vector<NodePtr> statements;

	while (!CheckToken(Token::Type::END_OF_FILE))
		statements.push_back(ReadFunctionOrStatement());

	return ast::Node::Make<ast::BlockNode>(statements);
}

Parser::NodePtr Parser::ReadFunctionOrStatement() {
	if (CheckToken(Token::Type::FUNCTION))
		return ReadFunctionDefinition();

	return ReadStatement();
}

Parser::NodePtr Parser::ReadStatement() {
	NodePtr statement;

	if (TokenPtr identifier = CheckToken(Token::Type::IDENTIFIER)) {
		if (CheckToken(Token::Type::ASSIGN)) {
			NodePtr value = ReadExpression();
			statement = ast::Node::Make<ast::ExrateNode>(identifier->GetIdentifier(), std::move(value));
		} else {
			RequireToken(Token::Type::PARENTHESIS_OPEN);
			statement = ReadFunctionCall(identifier->GetIdentifier());
		}
	} else if (CheckToken(Token::Type::VAR)) {
		statement = ReadVarDefinition();
	} else if (CheckToken(Token::Type::CURRENCY)) {
		statement = ReadCurrencyDeclaration();
	} else if (CheckToken(Token::Type::EXRATE)) {
		statement = ReadExrate();
	} else if (CheckToken(Token::Type::IF)) {
		statement = ReadConditionional();
	} else if (CheckToken(Token::Type::WHILE)) {
		statement = ReadLoop();
	} else if (CheckToken(Token::Type::RETURN)) {
		if (CheckToken(Token::Type::SEMICOLON)) {
			return ast::Node::Make<ast::ReturnNode>();
		} else {
			NodePtr value = ReadExpression();
			statement = ast::Node::Make<ast::ReturnNode>(std::move(value));
		}
	} else if (CheckToken(Token::Type::BRACKET_CLOSE)) {
		return nullptr;
	} else if (CheckToken(Token::Type::END_OF_FILE)) {
		return nullptr;
	} else {
		throw UnexpectedInputException();
	}

	RequireToken(Token::Type::SEMICOLON);
	return statement;
}

Parser::NodePtr Parser::ReadBlock() {
	std::vector<NodePtr> statements;

	if (CheckToken(Token::Type::BRACKET_OPEN)) {
		while (!CheckToken(Token::Type::BRACKET_CLOSE))
			statements.push_back(ReadStatement());
	} else {
		statements.push_back(ReadStatement());
	}

	return ast::Node::Make<ast::BlockNode>(statements);
}

Parser::NodePtr Parser::ReadCurrencyDeclaration() {
	std::vector<TokenPtr> currency_ids;

	do {
		auto id = RequireToken(Token::Type::IDENTIFIER);
		currency_ids.push_back(std::move(id));
	} while (CheckToken(Token::Type::COMMA));

	return ast::Node::Make<ast::CurrencyDeclarationNode>(std::move(currency_ids));
}

Parser::NodePtr Parser::ReadExrate() {
	return ast::Node::Make<ast::ExrateNode>(ReadAssign());
}

Parser::NodePtr Parser::ReadVarDefinition() {
	return ast::Node::Make<ast::VarDefinitionNode>(ReadAssign());
}

Parser::NodePtr Parser::ReadAssign() {
	auto id = RequireToken(Token::Type::IDENTIFIER)->GetIdentifier();
	RequireToken(Token::Type::ASSIGN);
	auto value = ReadExpression();

	return ast::Node::Make<ast::AssignNode>(id, std::move(value));
}

Parser::NodePtr Parser::ReadFunctionDefinition() {
	std::vector<std::string> args;
	const auto name = RequireToken(Token::Type::IDENTIFIER)->GetIdentifier();
	RequireToken(Token::Type::PARENTHESIS_OPEN);
	
	TokenPtr arg = CheckToken(Token::Type::IDENTIFIER);
	if (arg) {
		args.push_back(arg->GetIdentifier());
		
		while (CheckToken(Token::Type::COMMA)) {
			arg = RequireToken(Token::Type::IDENTIFIER);
			args.push_back(arg->GetIdentifier());
		}
	}
	RequireToken(Token::Type::PARENTHESIS_CLOSE);

	std::vector<NodePtr> statements;
	RequireToken(Token::Type::BRACKET_OPEN);
	
	while (!CheckToken(Token::Type::BRACKET_CLOSE))
		statements.push_back(ReadStatement());

	auto block = ast::Node::Make<ast::BlockNode>(statements);

	return ast::Node::Make<ast::FunctionDefinitionNode>(name, std::move(args), std::move(block));
}

Parser::NodePtr Parser::ReadFunctionCall(const std::string& name) {
	if (name == "prints") {
		const auto string = RequireToken(Token::Type::STRING)->GetString();
		RequireToken(Token::Type::PARENTHESIS_CLOSE);
		return ast::Node::Make<ast::PrintsCallNode>(string);
	}
	
	if (name == "printv") {
		const auto value = ReadExpression();
		RequireToken(Token::Type::PARENTHESIS_CLOSE);
		return ast::Node::Make<ast::PrintvCallNode>(std::move(value));
	}

	std::vector<NodePtr> args;
	if (!CheckToken(Token::Type::PARENTHESIS_CLOSE)) {
		args.push_back(ReadExpression());

		while (CheckToken(Token::Type::COMMA))
			args.push_back(ReadExpression());

		RequireToken(Token::Type::PARENTHESIS_CLOSE);
	}

	return ast::Node::Make<ast::CallNode>(name, std::move(args));
}

Parser::NodePtr Parser::ReadLoop() {
	RequireToken(Token::Type::PARENTHESIS_OPEN);
	NodePtr condition = ReadExpression();
	RequireToken(Token::Type::PARENTHESIS_CLOSE);
	NodePtr block = ReadBlock();

	return ast::Node::Make<ast::LoopNode>(std::move(condition), std::move(block));
}

Parser::NodePtr Parser::ReadConditionional() {
	RequireToken(Token::Type::PARENTHESIS_OPEN);
	NodePtr condition = ReadExpression();
	RequireToken(Token::Type::PARENTHESIS_CLOSE);
	NodePtr block = ReadBlock();
	
	if (CheckToken(Token::Type::ELSE)) {
		NodePtr else_block = ReadBlock();
		return ast::Node::Make<ast::ConditionNode>(std::move(condition),
			std::move(block), std::move(else_block));
	}

	return ast::Node::Make<ast::ConditionNode>(std::move(condition),
		std::move(block));
}

Parser::NodePtr Parser::ReadOperator(NodePtr(Parser::*readNextExpression)(),
		const std::initializer_list<Token::Type>& operators) {
	NodePtr lhs = (this->*readNextExpression)();
	while (auto token = CheckToken(operators)) {
		auto op = token->GetType();
		NodePtr rhs = (this->*readNextExpression)();
		lhs = ast::Node::Make<ast::BinaryOperatorNode>(op, std::move(lhs), std::move(rhs));
	}

	return lhs;
}

Parser::NodePtr Parser::ReadExpression() {
	return ReadOr();
}

Parser::NodePtr Parser::ReadOr() {
	return ReadOperator(&Parser::ReadAnd,
	{ Token::Type::OR });
}

Parser::NodePtr Parser::ReadAnd() {
	return ReadOperator(&Parser::ReadEqual,
	{ Token::Type::AND });
}

Parser::NodePtr Parser::ReadEqual() {
	return ReadOperator(&Parser::ReadRelation,
	{ Token::Type::EQUAL, Token::Type::UNEQUAL });
}

Parser::NodePtr Parser::ReadRelation() {
	return ReadOperator(&Parser::ReadSum,
	{ Token::Type::LESS, Token::Type::LESSEQ, Token::Type::GREATER, Token::Type::GREATEREQ });
}

Parser::NodePtr Parser::ReadSum() {
	return ReadOperator(&Parser::ReadMult,
	{ Token::Type::PLUS, Token::Type::MINUS });
}

Parser::NodePtr Parser::ReadMult() {
	return ReadOperator(&Parser::ReadValue,
	{ Token::Type::MULTIPLY, Token::Type::DIVIDE });
}

Parser::NodePtr Parser::ReadValue() {
	//TokenPtr unary = CheckToken({ Token::Type::PLUS, Token::Type::MINUS, Token::Type::INVERT }); // todo

	if (auto number = CheckToken(Token::Type::NUMBER)) {
		if(auto currency_id = CheckToken(Token::Type::IDENTIFIER))
			return ast::Node::Make<ast::NumberNode>(
				number->GetNumber(), currency_id->GetIdentifier());

		return ast::Node::Make<ast::NumberNode>(number->GetNumber());
	}
	
	if (auto identifier = CheckToken(Token::Type::IDENTIFIER)) {
		if (CheckToken(Token::Type::PARENTHESIS_OPEN)) {
			return ReadFunctionCall(identifier->GetIdentifier());
		}

		if (CheckToken(Token::Type::AS)) {
			auto currency_id = RequireToken(Token::Type::IDENTIFIER);
			return ast::Node::Make<ast::AsNode>(
				identifier->GetIdentifier(), currency_id->GetIdentifier());
		}

		return ast::Node::Make<ast::IdentifierNode>(identifier->GetIdentifier());
	}

	RequireToken(Token::Type::PARENTHESIS_OPEN);
	return ReadExpression();
}
