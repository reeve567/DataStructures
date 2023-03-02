#include "DynamicList.h"
#include <iostream>

DynamicNode* DynamicList::getNth(int pos) {
    // start with head as pos 0
    int count = 0;
    DynamicNode* node = head;
    // move up to pos, and making sure things exist along the way
    while (count != pos) {
        if (node == nullptr) {
            return nullptr;
        }
        node = node->next;
        count++;
    }

    // Only return the node if it's in the right position.
    if (count == pos) {
        return node; // this might return nullptr if the node doesn't exist, but that meets the requirements
    } else { // not at the right position
        return nullptr;
    }
}

DynamicNode* DynamicList::findOrInsert(int x) {
    // create node to insert
    DynamicNode* toInsert = new DynamicNode();
    toInsert->info = x;
    toInsert->next = nullptr;

    if (head == nullptr) {
        head = toInsert;
        return toInsert;
    }

    DynamicNode* node = head;

    // look over the list to find something that matches
    while (node->info != x) {
        // deal with finding the end of the list before it tries to move on
        if (node->next == nullptr) {
            // add to end of list
            node->next = toInsert;
            return toInsert;
        }
        node = node->next;
    }

    // insert is unused
    delete toInsert;
    // return since it was found, in the case of head being a nullptr it will get her
    return node;
}

int main() {
    DynamicList list = DynamicList();
    list.insertFirst(1);
    list.insertFirst(2);

    std::cout << "a)\n";
    list.print();
    std::cout << list.findOrInsert(2)->info << "\n";
    list.print();

    std::cout << "b)\n";
    list.print();
    std::cout << list.findOrInsert(1)->info << "\n";
    list.print();

    std::cout << "c)\n";
    list.insertFirst(3);
    list.print();
    std::cout << list.findOrInsert(4)->info << "\n";
    list.print();

    std::cout << "d)\n";
    list.print();
    std::cout << list.findOrInsert(4)->info << "\n";
    list.print();

    std::cout << "e)\n";
    list.print();
    std::cout << list.findOrInsert(2)->info << "\n";
    list.print();

    std::cout << "f)\n";
    DynamicList list2 = DynamicList();
    list2.print();
    std::cout << list2.findOrInsert(1)->info << "\n";
    list2.print();
}