// File: BinaryOperator.hpp
#pragma once

#include <sstream>

#include "../../Lexer/Lexer.h"
#include "Node.h"

namespace ast {

class BinaryOperatorNode : public Node
{
  public:
    BinaryOperatorNode(Token::Type op, NodePtr&& lhs, NodePtr&& rhs);

    ValuePtr evaluate(/*Scope& scope*/) const override;

  private:
    const Token::Type op_;
    const NodePtr lhs_;
    const NodePtr rhs_;
};

} // namespace ast
