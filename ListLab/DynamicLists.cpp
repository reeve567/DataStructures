#include "DynamicList.h"
#include <iostream>

// inserts x at the beginning of the list
void DynamicList::insertFirst(int x) {
	DynamicNode* q = new DynamicNode;
	q->info = x;
	q->next = head;
	head = q;
}

void DynamicList::print() {
	if (head == nullptr) {
		std::cout << "Empty list\n";
	}

	DynamicNode* p = head;
	while (p != nullptr) {
		std::cout << p->info;
		if (p->next != nullptr) {
			std::cout << "->";
		}
		else {
			std::cout << "\n";
		}
		p = p->next;
	}
}

// inserts x after p
void DynamicList::insertAfter(DynamicNode *p, int x) {

	if (p == nullptr) {
		std::cout << "void insertion\n";
		exit(1);
	}

	DynamicNode* q = new DynamicNode;
	q->info = x;
	q->next = p->next;
	p->next = q;
} // end insertAfter


DynamicNode* DynamicList::search(int x) {
	DynamicNode* p = head;
	for (p; p != nullptr; p = p->next)
		if (p->info == x)
			return p;

	return nullptr; // x is not on the list
} // end search


/*int main()
{
    DynamicList newList = DynamicList();
    
    newList.print();

    // test inserts
    newList.insertFirst(1);
    newList.insertFirst(2);
    newList.insertFirst(5);
    newList.insertFirst(3);

    std::cout << "The list after inserts: ";
    newList.print();
    
    // test search method and then insert after
    DynamicNode* first = newList.search(3);
    std::cout << "Search method works for when node is at head of list: ";
    std::cout << first->info << "\n";

    DynamicNode* notFound = newList.search(7); // for a node not found in the list
    if (notFound == nullptr)
       std::cout << "7 was not found\n";
    // std::cout << notFound->info;// avoid doing this... 

    DynamicNode* dn = newList.search(2); // for a node in the list
    std::cout << "Search method works for when node is in list: ";
    std::cout << dn->info << "\n";

    newList.insertAfter(dn, 4);
    std::cout << "The list after using insertAfter method on the node we just found with search: ";
    newList.print();

    return 0;
}*/
