#include "NumberValue.h"

namespace ast {

NumberValue::NumberValue(double number)
    : Value(Value::Type::Number), value_(number) {

}

bool NumberValue::operator==(const Value& rhs) const {
    return Value::operator==(rhs) && asNumber() == rhs.asNumber();
}

double NumberValue::asNumber() const {
	return value_;
}

//std::ostream& NumberValue::show(std::ostream& out) const {
//    return out << value_;
//}

} // namespace ast
