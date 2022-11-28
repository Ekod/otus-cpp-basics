#include <iostream>

#include "headers/contiguous.h"
#include "headers/doubly_linked_list.h"

template<typename T>
void demoContainer(T &cnt, std::string message) {
    std::cout << message << std::endl;
    std::cout << "Add 0...9" << std::endl;
    for (int i = 0; i < 10; i++) {
        cnt.push_back(i);
    }
    cnt.show();
    std::cout << "Size: " << cnt.size() << std::endl;
    std::cout << "Delete items at indices 3, 4, 5" << std::endl;
    for (int i = 3; i < 6; ++i) {
        cnt.erase(i);
        cnt.show();
    }
    std::cout << "Add item to the beginning(10)" << std::endl;
    cnt.insert(0, 10);
    cnt.show();
    std::cout << "Add item to the middle(20)" << std::endl;
    cnt.insert(cnt.size() / 2, 20);
    cnt.show();
    std::cout << "Add item to the end(30)" << std::endl;
    cnt.push_back(30);
    cnt.show();
    std::cout << std::endl;
}

int main() {
    ContiguousContainer<int> ccnt;
    demoContainer(ccnt, "=== Contiguous container ===");

    DoublyLinkedList<int> dll;
    demoContainer(dll, "=== DoublyLinkedList ===");
    return (0);
}
