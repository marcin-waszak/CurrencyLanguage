#pragma once

#include <memory>
#include "Value.h"

namespace ast {

class Node;
using NodePtr = std::unique_ptr<const Node>;

class Node {
public:
	Node();
	virtual ~Node();
	virtual ValuePtr evaluate(/*Scope& scope*/) const = 0;
	ValuePtr run() const;

	template <typename T, typename ...Args>
	static NodePtr make(Args&&... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
};

} // namespace ast
