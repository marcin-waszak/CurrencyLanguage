#pragma once

#include "Value.h"

namespace ast {

class NumberValue : public Value {
  public:
    NumberValue(double number);

	double asNumber() const override;

    bool operator==(const Value& rhs) const override;

    //std::ostream& show(std::ostream& out) const override;

  private:
    const double value_;
};

} // namespace ast
