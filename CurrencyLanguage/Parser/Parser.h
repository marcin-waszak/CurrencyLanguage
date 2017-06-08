#pragma once

#include "AST/Node.h"
#include "AST/BlockNode.h"
#include "AST/AssignNode.h"
#include "AST/CurrencyDeclarationNode.h"
#include "AST/ConditionNode.h"
#include "AST/AssignNode.h"
#include "AST/ExrateNode.h"
#include "AST/VarDefinitionNode.h"
#include "AST/FunctionDefinitionNode.h"
#include "AST/CallNode.h"
#include "AST/PrintsCallNode.h"
#include "AST/PrintvCallNode.h"
#include "AST/LoopNode.h"
#include "AST/BinaryOperatorNode.h"
#include "AST/NumberNode.h"
#include "AST/AsNode.h"
#include "AST/IdentifierNode.h"
#include "AST/ReturnNode.h"
#include "UnexpectedInputException.h"
#include "../Lexer/Lexer.h"

class Parser {
public:
	using NodePtr = ast::NodePtr;
	using TokenPtr = std::unique_ptr<Token>;

	Parser(Lexer& lexer);

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
	NodePtr ReadFunctionCall(const std::string& name);

	NodePtr ReadLoop();
	NodePtr ReadConditionional();

	NodePtr ReadExpression();
	NodePtr ReadOperator(
		NodePtr(Parser::*readNextExpression)(),
		const std::initializer_list<Token::Type>& operators);
	NodePtr ReadOr();
	NodePtr ReadAnd();
	NodePtr ReadEqual();
	NodePtr ReadRelation();
	NodePtr ReadSum();
	NodePtr ReadMult();

	NodePtr ReadValue();

	TokenPtr CheckToken(Token::Type expected);
	TokenPtr CheckToken(const std::initializer_list<Token::Type>& expected);
	TokenPtr RequireToken(Token::Type expected);

	Token& GetToken();
	Token& Advance();

	Lexer& lexer_;
};
