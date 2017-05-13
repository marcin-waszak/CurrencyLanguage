#include "Void.h"

Void::Void() : Value(Value::Type::Void)
{

}

ValuePtr Void::evaluate() const
{
	return Value::evaluate();
}
