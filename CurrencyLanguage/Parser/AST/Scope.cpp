#include "Scope.h"

#include <stdexcept>

namespace ast {

Scope::Scope()
    : parent_(nullptr) {

}

Scope::Scope(Scope& parent)
    : parent_(&parent) {

}

ValuePtr& Scope::Lookup(const std::string& idname) {
    auto it = scope_.find(idname);
    if (it != scope_.end())
        return it->second;
    else if (parent_)
        return parent_->Lookup(idname);
    else
        throw std::runtime_error("Undeclared variable: " + idname);
}

ValuePtr& Scope::Add(const std::string& idname) {
    if (scope_.count(idname))
        throw std::runtime_error("Variable already declared: " + idname);
    else
        return scope_[idname];
}

} // namespace ast
