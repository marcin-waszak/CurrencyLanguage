#include "Node.h"

namespace ast {

Node::Node() {

}


Node::~Node() {

}

ValuePtr Node::run() const {
	//	Scope root_scope;
		//try {
	return evaluate(/*root_scope*/);
	//}
	//catch () {

	//} TODO
}

} // namespace ast
