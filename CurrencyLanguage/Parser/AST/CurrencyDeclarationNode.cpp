#include "CurrencyDeclarationNode.h"

namespace ast {

	CurrencyDeclarationNode::CurrencyDeclarationNode(std::vector<TokenPtr>&& currencies)
		: currencies_(std::move(currencies)) {

	}

} // namespace ast
