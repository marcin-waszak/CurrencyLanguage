#pragma once

#include <memory>
#include "Value.h"
#include "Scope.h"

namespace ast {

class Node;
using NodePtr = std::unique_ptr<const Node>;

class Node {
public:
	Node();
	virtual ~Node();
	virtual ValuePtr Evaluate(Scope& scope) const = 0;
	ValuePtr Run() const;

	template <typename T, typename ...Args>
	static NodePtr Make(Args&&... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
};

} // namespace ast
