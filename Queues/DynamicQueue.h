#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

struct DynamicNode{ // node is the same as in the dynamic list code 
  char info;
  DynamicNode *next;
};

class DynamicQueue {
public:
	//---------------------------------------------------------------
	// constructors
	//---------------------------------------------------------------
	DynamicQueue();

	//---------------------------------------------------------------
	// methods (inserts and deletes)
	//---------------------------------------------------------------
	bool empty();
	void insert(char x);
	char remove();
    int getSize();
    void print();
    DynamicNode* find(char key);
	DynamicNode* remove(char key);

private:
	DynamicNode* front;
	DynamicNode* rear;
    int size = 0;
};
#endif

