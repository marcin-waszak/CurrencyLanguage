#pragma once

#include "Node.h"

namespace ast {

class ReturnNode : public Node
{
  public:
    class ReturnHelper {
      public:
        ReturnHelper(ValuePtr&& value)
            : return_value(std::move(value)) {

		}

        ValuePtr return_value;
    };


	ReturnNode(NodePtr&& expression);
	ReturnNode();

    ValuePtr Evaluate(Scope& scope) const override;

  private:
    const NodePtr expression_;
};

} // namespace ast
