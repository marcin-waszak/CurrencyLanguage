#pragma once

#include <map>
#include <string>

#include "Value.h"

namespace ast {

class Scope
{
  public:
    Scope();
    Scope(Scope& parent);

    ValuePtr& Lookup(const std::string& idname);
    ValuePtr& Add(const std::string& idname);

  private:
    Scope* const parent_;
    std::map<std::string, ValuePtr> scope_;
};

} // namespace ast
