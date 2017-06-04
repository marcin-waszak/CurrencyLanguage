#pragma once

#include <memory>
#include <vector>

namespace ast {

class Value;
using ValuePtr = std::shared_ptr<const Value>;

class Value : public std::enable_shared_from_this<Value> {
public:
	enum class Type {
		Number,
		String,
		Void,
	};

	virtual ~Value() { }

	template <typename T, typename ...Args>
	static ValuePtr make(Args&&... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	virtual double asNumber() const;

	virtual bool operator==(const Value& rhs) const;
	virtual operator bool() const;

	ValuePtr evaluate() const;

	//virtual std::ostream& show(std::ostream& out) const;

	const Type type;

protected:
	Value(Type type);
};

} // namespace ast
