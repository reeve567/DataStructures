#include "Stack.h"
#include <iostream>

//-------------------------------------------------------------------------------
// constructors
//-------------------------------------------------------------------------------
/********************************************************************************
default constructor
********************************************************************************/
Stack::Stack() {
	top = -1;
}

/********************************************************************************
methods (insert and delete)
********************************************************************************/
bool Stack::empty() {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

void Stack::push(char x) {
	if (top == STACKSIZE - 1) {
		std::cout << "Stack Overflow PUSH" << std::endl;
		exit(1);
	}

	items[++top] = x;
}

char Stack::pop() {
	if (empty()) {
		std::cout << "Stack Underflow POP" << std::endl;
		exit(1);
	}

	return items[top--];
}

char Stack::peek() {
	if (empty()) {
		std::cout << "Stack Underflow PEEK" << std::endl;
		exit(1);
	}

	return items[top];
}