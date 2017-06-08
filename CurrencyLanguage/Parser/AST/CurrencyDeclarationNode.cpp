#include "CurrencyDeclarationNode.h"

namespace ast {

	CurrencyDeclarationNode::CurrencyDeclarationNode(std::vector<TokenPtr>&& currencies)
		: currencies_(std::move(currencies)) {

	}

	ValuePtr CurrencyDeclarationNode::Evaluate(Scope& scope) const
	{
		return Value::Make<Void>();
	}

} // namespace ast
