#include "Parser.h"

Parser::TokenPtr Parser::CheckToken(Token::Type expected) {
	TokenPtr token(new Token(lexer_.GetToken()));
	if (token->GetType() != expected)
		return nullptr;

	Advance();
	return token;
}

Parser::TokenPtr Parser::RequireToken(Token::Type expected)
{
	TokenPtr token = CheckToken(expected);

	if (token)
		return token;

	throw "Unexpected input"; // TODO
}

//Parser::TokenPtr Parser::RequireToken(
//	const std::initializer_list<Token>& expected) {
//	return Token();
//}

Token& Parser::GetToken() {
	return lexer_.GetToken();
}

Token& Parser::Advance() {
	return lexer_.ReadToken();
}

Parser::NodePtr Parser::Parse() {
	Advance();
	return ReadMain();
}

Parser::NodePtr Parser::ReadMain() {
	std::vector<NodePtr> subtrees;

	while (!CheckToken(Token::Type::END_OF_FILE)) {
		NodePtr line = ReadFunctionOrStatement();
		subtrees.push_back(std::move(line));
	}

	return ast::Node::make<ast::BlockNode>(subtrees);
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
			statement = ast::Node::make<ast::AssignNode>(identifier->GetIdentifier(), std::move(value));
		} else {
			RequireToken(Token::Type::PARENTHESIS_OPEN);
			statement = ReadFunctionCall();
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
			return ast::Node::make<ast::ReturnNode>();
		} else {
			NodePtr value = ReadExpression();
			statement = ast::Node::make<ast::Return>(std::move(value));
		}
	} else if (CheckToken(Token::Type::BRACKET_CLOSE)) {
		return nullptr;
	} else if (CheckToken(Token::Type::END_OF_FILE)) {
		return nullptr;
	} else {
		throw "Unexpected input"; // TODO
	}
}
/*
Parser::NodePtr Parser::ReadBlock() {
	return NodePtr();
}
*/
Parser::NodePtr Parser::ReadCurrencyDeclaration() {
	std::vector<TokenPtr> currency_ids;

	do {
		auto id = RequireToken(Token::Type::IDENTIFIER);
		currency_ids.push_back(std::move(id));
	} while (CheckToken(Token::Type::COMMA));

	return ast::Node::make<ast::CurrencyDeclarationNode>(std::move(currency_ids));
}
/*
Parser::NodePtr Parser::ReadExrate() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadVarDefinition() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadAssign() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadFunctionDefinition() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadFunctionCall() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadLoop() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadConditionional() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadExpression() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadOperator(NodePtr (Parser::* readNextExpression)(),
	const std::initializer_list<Token::Type>& operators) {
	return NodePtr();
}

Parser::NodePtr Parser::ReadOr() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadAnd() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadEqual() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadRelation() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadSum() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadMult() {
	return NodePtr();
}

Parser::NodePtr Parser::ReadValue() {
	return NodePtr();
}
*/
