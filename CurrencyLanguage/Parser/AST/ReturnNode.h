#pragma once

#include "Node.h"

namespace ast {

class ReturnNode : public Node
{
  public:
    //class UglyHack
    //{
    //  public:
    //    UglyHack(ValuePtr&& value)
    //        : return_value(std::move(value))
    //    { }

    //    ValuePtr return_value;
    //};


	ReturnNode(NodePtr&& expression);
	ReturnNode();

    ValuePtr evaluate(/*Scope& scope*/) const override;

  private:
    const NodePtr expression_;
};

} // namespace ast
