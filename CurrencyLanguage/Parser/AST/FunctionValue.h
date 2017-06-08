#pragma once

#include "Value.h"
#include "FunctionDefinitionNode.h"

namespace ast {

class FunctionValue : public Value {
  public:
	FunctionValue(const FunctionDefinitionNode* function_ptr);

	const FunctionDefinitionNode* asFunction() const override;

    //bool operator==(const Value& rhs) const override;

    //std::ostream& show(std::ostream& out) const override;

  private:
	const FunctionDefinitionNode* function_ptr_;
};

} // namespace ast
