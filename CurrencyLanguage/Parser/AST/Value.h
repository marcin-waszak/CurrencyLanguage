#pragma once

#include <memory>
#include <vector>
#include <type_traits>
//#include "Node.h"
//#include "FunctionDefinitionNode.h"

namespace ast {
class FunctionDefinitionNode;//////////
class Value;
using ValuePtr = std::shared_ptr<const Value>;

class Value : public std::enable_shared_from_this<Value> {
public:
	enum class Type {
		Number,
		String,
		Function,
		Void,
	};

	virtual ~Value();

	template <typename T, typename ...Args>
	static ValuePtr Make(Args&&... args) {
		return std::make_shared<typename std::add_const<T>::type>(std::forward<Args>(args)...);
	}

	virtual double asNumber() const;
	virtual const FunctionDefinitionNode* asFunction() const;

	virtual bool operator==(const Value& rhs) const;
	virtual operator bool() const;

	ValuePtr Evaluate() const;

	//virtual std::ostream& show(std::ostream& out) const;

	const Type type;

protected:
	Value(Type type);
};

} // namespace ast
