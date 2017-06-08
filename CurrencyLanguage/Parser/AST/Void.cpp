#include "Void.h"

namespace ast {

Void::Void() : Value(Value::Type::Void)
{

}

ValuePtr Void::Evaluate(Scope& scope) const
{
	return Value::Evaluate();
}

} // namespace ast
