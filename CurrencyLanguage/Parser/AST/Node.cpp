#include "Node.h"

Node::Node() {

}


Node::~Node() {

}

ValuePtr Node::run() const {
//	Scope root_scope;
	//try {
		return evaluate(/*root_scope*/);
	//}
	//catch (const Return::UglyHack& early_return) {
	//	return early_return.return_value;
	//}
}
