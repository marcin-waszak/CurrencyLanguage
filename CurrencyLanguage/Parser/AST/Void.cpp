#include "Void.h"

namespace ast {

Void::Void() : Value(Value::Type::Void)
{

}

ValuePtr Void::evaluate() const
{
	return Value::evaluate();
}

} // namespace ast
