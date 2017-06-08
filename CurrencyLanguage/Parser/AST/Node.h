#pragma once

#include <memory>
#include <type_traits>
#include "Value.h"
#include "Scope.h"

namespace ast {

class Node;
using NodePtr = std::unique_ptr<const Node>;

class Node {
public:
	virtual ~Node();
	virtual ValuePtr Evaluate(Scope& scope) const = 0;
	ValuePtr Run() const;

	template <typename T, typename ...Args>
	static NodePtr Make(Args&&... args) {
		return std::make_unique<typename std::add_const<T>::type>(std::forward<Args>(args)...);
	}

protected:
	Node();
};

} // namespace ast
