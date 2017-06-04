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

double Value::asNumber() const
{
	throw /*BadResultCast*/("Not a number");
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
//	throw /*BadResultCast*/("Not showable");
//}

} // namespace ast
