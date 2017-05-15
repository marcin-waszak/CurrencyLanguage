#pragma once

#include "AST/Node.h"
#include "AST/BlockNode.h"
#include "AST/AssignNode.h"
#include "AST/CurrencyDeclarationNode.h"
#include "AST/ConditionNode.h"
#include "../Lexer/Lexer.h"

class Parser
{
public:
	using NodePtr = ast::NodePtr;
	using TokenPtr = std::unique_ptr<Token>;

	NodePtr Parse();

private:
	NodePtr ReadMain();
	NodePtr ReadFunctionOrStatement();

	NodePtr ReadStatement();
	NodePtr ReadBlock();

	NodePtr ReadCurrencyDeclaration();
	NodePtr ReadExrate();

	NodePtr ReadVarDefinition();
	NodePtr ReadAssign();
	NodePtr ReadFunctionDefinition();
	NodePtr ReadFunctionCall();

	NodePtr ReadLoop();
	NodePtr ReadConditionional();

//	NodePtr ReadPrint();

	NodePtr ReadExpression();
	NodePtr ReadOperator(
		NodePtr(Parser::*readNextExpression)(),///////////
		const std::initializer_list<Token::Type>& operators);
	NodePtr ReadOr();
	NodePtr ReadAnd();
	NodePtr ReadEqual();
	NodePtr ReadRelation();
	NodePtr ReadSum();
	NodePtr ReadMult();

	NodePtr ReadValue();

	TokenPtr CheckToken(Token::Type expected);
	TokenPtr RequireToken(Token::Type expected);
	//TokenPtr RequireToken(const std::initializer_list<Token>& expected);

	Token& GetToken();
	Token& Advance();

	Lexer lexer_;
};
