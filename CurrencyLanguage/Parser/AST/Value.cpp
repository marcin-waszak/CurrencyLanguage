#include "Value.h"
#include "FunctionDefinitionNode.h"
#include "BadCastException.h"

namespace ast {

Value::Value(Type type) : type(type) {

}

Value::~Value() {

}

ValuePtr Value::Evaluate() const {
	return shared_from_this();
}

double Value::asNumber() const
{
	throw  BadCastException("Not a number");
}

const FunctionDefinitionNode* Value::asFunction() const
{
	throw BadCastException("Not a function");
}


bool Value::operator==(const Value& rhs) const
{
	return type == rhs.type;
}

Value::operator bool() const
{
	return true;
}

//std::ostream& Value::show(std::ostream&) const
//{
//	throw BadCastException("Not showable");
//}

} // namespace ast
