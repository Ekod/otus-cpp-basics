#include "gtest/gtest.h"
#include "../src/doubly_linked_list.h"

TEST(DoublyLinkedList, CheckIfExists) {
    DoublyLinkedList<int> ccnt;

    ASSERT_EQ(ccnt.size(), 0);
}

TEST(DoublyLinkedList, PushBack) {
    DoublyLinkedList<int> ccnt;

    ccnt.push_back(30);
    int lastElemIdx = ccnt.size() - 1;
    int lastElem = ccnt[lastElemIdx];

    ASSERT_EQ(lastElem, 30);
}

TEST(DoublyLinkedList, PushStart) {
    DoublyLinkedList<int> ccnt;
    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    ccnt.insert(0, 30);
    int firstElem = ccnt[0];

    ASSERT_EQ(firstElem, 30);
}

TEST(DoublyLinkedList, PushMiddle) {
    DoublyLinkedList<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int pos = ccnt.size() / 2;
    ccnt.insert(pos, 20);

    int elem = ccnt[pos];

    ASSERT_EQ(elem, 20);
}

TEST(DoublyLinkedList, PopBack) {
    DoublyLinkedList<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    ccnt.erase(9);
    ASSERT_EQ(ccnt[ccnt.size() - 1], 9);
}

TEST(DoublyLinkedList, PopStart) {
    DoublyLinkedList<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    ccnt.erase(0);
    ASSERT_EQ(ccnt[0], 1);
}

TEST(DoublyLinkedList, PopMiddle) {
    DoublyLinkedList<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int midElemPos = ccnt.size() / 2;
    ccnt.erase(5);

    int midElemPostErase = ccnt[midElemPos];

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
