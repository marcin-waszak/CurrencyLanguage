#include "Value.h"

namespace ast {

Value::Value(Type type) : type(type)
{

}

Value::~Value()
{

}

ValuePtr Value::evaluate() const {
	return shared_from_this();
}

int Value::asInt() const
{
	throw /*BadResultCast*/("Not an integer");
}

const std::vector<ValuePtr>& Value::asList() const
{
	throw /*BadResultCast*/("Not a list");
}

//const FunctionValue& Value::asFunction() const
//{
//	throw /*BadResultCast*/("Not a function");
//}

bool Value::operator==(const Value& rhs) const
{
	return type == rhs.type;
}

Value::operator bool() const
{
	return true;
}

std::ostream& Value::show(std::ostream&) const
{
	throw /*BadResultCast*/("Not showable");
}

} // namespace ast
