#include "gtest/gtest.h"
#include "../src/contiguous.h"

TEST(ContiguousContainer, CheckIfExists) {
    ContiguousContainer<int> ccnt;

    ASSERT_EQ(ccnt.size(), 0);
}

TEST(ContiguousContainer, PushBack) {
    ContiguousContainer<int> ccnt;

    ccnt.push_back(30);
    int lastElemIdx = ccnt.size() - 1;
    int lastElem = ccnt[lastElemIdx];

    ASSERT_EQ(lastElem, 30);
}

TEST(ContiguousContainer, PushStart) {
    ContiguousContainer<int> ccnt;
    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    ccnt.insert(0, 30);
    int firstElem = ccnt[0];

    ASSERT_EQ(firstElem, 30);

}

TEST(ContiguousContainer, PushMiddle) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int pos = ccnt.size() / 2;
    ccnt.insert(pos, 20);

    int elem = ccnt[pos];

    ASSERT_EQ(elem, 20);

}

TEST(ContiguousContainer, PopBack) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int lastElemIdxPreErase = ccnt.size() - 1;
    ccnt.erase(lastElemIdxPreErase);
    int lastElemIdxPostErase = ccnt.size() - 1;

    ASSERT_EQ(ccnt[lastElemIdxPostErase], 8);
}

TEST(ContiguousContainer, PopStart) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    ccnt.erase(0);
    ASSERT_EQ(ccnt[0], 1);
}

TEST(ContiguousContainer, PopMiddle) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int midElemPos = ccnt.size() / 2;
    ccnt.erase(midElemPos);

    int midElemPostErase = ccnt[midElemPos];

    ASSERT_EQ(midElemPostErase, 6);
}

TEST(ContiguousContainer, GetElement) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int want = 3;
    int got = ccnt[3];

    ASSERT_EQ(want, got);
}

TEST(ContiguousContainer, GetSize) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int want = 10;
    int got = ccnt.size();

    ASSERT_EQ(want, got);
}
