#include <iostream>
#include "DynamicQueue.h"

void runTest(char key, DynamicQueue* queue);

int QUEUESIZE = 4;

int main() {
    DynamicQueue* one = new DynamicQueue();

	std::cout << "Test Case 1:\n";
	runTest('a', one);
	runTest('b', one);
	runTest('w', one);
	runTest('b', one);
	runTest('z', one);
	runTest('e', one);

	DynamicQueue* two = new DynamicQueue();
	std::cout << "Test Case 2:\n";
	runTest('b', two);
	runTest('c', two);
	runTest('t', two);
	runTest('s', two);
	runTest('a', two);
	runTest('c', two);
	runTest('c', two);
	runTest('s', two);

}

void runTest(char key, DynamicQueue* queue) {
    std::cout << "Read key " << key << ".";

	DynamicNode* found = queue->find(key);
	if (found != nullptr && found->next == nullptr) {
		std::cout << " Key " << key << " is already rear.";
	} else {
		DynamicNode* node = queue->remove(key);
		if (node != nullptr) {
			delete node;
			std::cout << " Key already in queue, moving " << key << " to rear.";
			queue->insert(key);
		} else {
			if (queue->getSize() == QUEUESIZE) {
				std::cout << " Queue is full, removing front.";
				queue->remove();
			}

			if (queue->getSize() < QUEUESIZE) {
				std::cout << " Inserting " << key << " in rear.";
				queue->insert(key);
			} else {
				std::cout << "too many elements";
				exit(1);
			}
		}
	}

    std::cout << " Queue: ";
    queue->print();
    std::cout << "\n";
}