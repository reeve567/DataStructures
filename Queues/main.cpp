#include <iostream>
#include "DynamicQueue.h"

int main() {
    DynamicQueue* queue = new DynamicQueue();
    int QUEUESIZE = 4;
}

void runTest(char key, int max, DynamicQueue* queue) {
    std::cout << "Read key " << key << ".";

    DynamicNode* node = queue->remove(key);
    if (node != nullptr) {
		delete node;
		queue->insert(key);
    } else {
	    if (queue->getSize() < max) {
		    std::cout << " Inserting " << key << " in rear.";
		    queue->insert(key);
	    } else if (queue->getSize() == max) {

	    } else {
		    std::cout << "too many elements";
		    exit(1);
	    }
    }

    std::cout << " Queue: ";
    queue->print();
    std::cout << "\n";
}