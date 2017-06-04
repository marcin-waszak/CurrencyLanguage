#include "Node.h"

namespace ast {

Node::Node() {

}


Node::~Node() {

}

ValuePtr Node::Run() const {
	//	Scope root_scope;
		//try {
	return Evaluate(/*root_scope*/);
	//}
	//catch () {

	//} TODO
}

} // namespace ast
