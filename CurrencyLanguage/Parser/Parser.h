#pragma once

#include "AST/Node.h"
#include "../Lexer/Lexer.h"

class Parser
{
public:
//	using NodePtr = ast::NodePtr;
//	using TokenPtr = std::unique_ptr<Token>;

	NodePtr Parse();

private:
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

};
