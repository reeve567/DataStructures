#include "DynamicQueue.h"
#include <iostream>
#include <stdlib.h>

//-------------------------------------------------------------------------------
// constructors
//-------------------------------------------------------------------------------
/********************************************************************************
default constructor
********************************************************************************/
DynamicQueue::DynamicQueue() {
	front = nullptr;
	rear = nullptr;

}

//---------------------------------------------------------------
// methods (inserts and deletes)
//---------------------------------------------------------------
bool DynamicQueue::empty() {
	return (front == nullptr);
}

void DynamicQueue::insert(char x) {
	DynamicNode* p = new DynamicNode;
	p->info =x;
	p->next = nullptr;

	if (empty()) {
		front = p;
	}
	else {
		rear->next = p;
	}

    size++;
	rear = p;
}

char DynamicQueue::remove() {
	if (empty()) {
		std::cout << "queue underflow";
		exit(1);
	}

	DynamicNode* p = front;
	char temp = p->info;
	front = p->next;
	delete p;
	if (front == nullptr)
		rear = nullptr;

    size--;
	return temp;
}

int DynamicQueue::getSize() {
    return size;
}

void DynamicQueue::print() {
    for (DynamicNode* node = front; node != nullptr; node = node->next) {
        std::cout << "node";
        if (node->next != nullptr) {
            std::cout << "->";
        }
    }
}

DynamicNode* DynamicQueue::remove(char key) {
	if (front->info == key) {
		DynamicNode* node = front;
		front = front->next;
		size--;
		return node;
	}

	DynamicNode* previous = front;
	for (DynamicNode* node = front->next; node != nullptr; node = node->next) {
		if (node->info == key) {
			previous->next = node->next; // this should work if it's nullptr too
			size--;
			return node;
		}
	}

	return nullptr;
}

DynamicNode* DynamicQueue::find(char key, DynamicNode* previous, DynamicNode* last) {
	DynamicNode* found = nullptr;
    for (DynamicNode* node = front; node != nullptr; node = node->next) {
        previous = node;
        if (node->info == key) {
            found = node;
        }
		if (node->next == nullptr) {
			last = node;
		}
    }
    return found;
}