#pragma once
#include "Node.h"
#include "Void.h"
#include "../../Lexer/Token.h"

#include <vector>

namespace ast {

using TokenPtr = std::unique_ptr<Token>;

class CurrencyDeclarationNode : public Node
{
public:
	CurrencyDeclarationNode(std::vector<TokenPtr>&& currencies);

	ValuePtr Evaluate(Scope& scope) const override;

private:
	std::vector<TokenPtr> currencies_;
};

} // namespace ast
