#include "gtest/gtest.h"
#include "../src/doubly_linked_list.h"

TEST(DoublyLinkedList, CheckIfExists) {
    DoublyLinkedList<int> dll;

    ASSERT_EQ(dll.size(), 0);
}

TEST(DoublyLinkedList, PushBack) {
    DoublyLinkedList<int> _cnt;
    _cnt.push_back(999);
    ASSERT_EQ(_cnt[0], 999);
}

TEST(DoublyLinkedList, PushStart) {
    DoublyLinkedList<int> dll;
    for (int i = 0; i < 10; i++) {
        dll.push_back(i);
    }

    dll.insert(0, 30);
    int firstElem = dll[0];

    ASSERT_EQ(firstElem, 30);
}

TEST(DoublyLinkedList, PushMiddle) {
    DoublyLinkedList<int> dll;

    for (int i = 0; i < 10; i++) {
        dll.push_back(i);
    }

    int pos = dll.size() / 2;
    dll.insert(pos, 20);

    int elem = dll[pos];

    ASSERT_EQ(elem, 20);
}

TEST(DoublyLinkedList, PopBack) {
    DoublyLinkedList<int> dll;

    for (int i = 0; i < 10; i++) {
        dll.push_back(i);
    }

    dll.erase(dll.size() - 1);
    ASSERT_EQ(dll[dll.size() - 1], 9);
}

TEST(DoublyLinkedList, PopStart) {
    DoublyLinkedList<int> dll;

    for (int i = 0; i < 10; i++) {
        dll.push_back(i);
    }

    dll.erase(0);
    ASSERT_EQ(dll[0], 1);
}

TEST(DoublyLinkedList, PopMiddle) {
    DoublyLinkedList<int> dll;

    for (int i = 0; i < 10; i++) {
        dll.push_back(i);
    }

    int midElemPos = dll.size() / 2;
    dll.erase(midElemPos);

    int midElemPostErase = dll[midElemPos];

    ASSERT_EQ(midElemPostErase, 6);
}

TEST(DoublyLinkedList, GetElement) {
    DoublyLinkedList<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int want = 3;
    int got = ccnt[3];

    ASSERT_EQ(want, got);
}

TEST(DoublyLinkedList, GetSize) {
    DoublyLinkedList<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int want = 10;
    int got = ccnt.size();

    ASSERT_EQ(want, got);
}
