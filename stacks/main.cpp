#include <iostream>
#include "Stack.h"

int main() {
    char lastName[] = {'B', 'L', 'A', 'K', 'E'};
    int size = sizeof(lastName) / sizeof(*lastName);

    Stack stack = Stack();

    for (int i = 0; i < size; i++) {
        stack.push(lastName[i]);
        std::cout << lastName[i];
    }

    std::cout << '\n';

    for (int i = 0; i < size; i++) {
        std::cout << stack.pop();
    }

    std::cout << '\n';
}
