#include "gtest/gtest.h"
#include "../src/contiguous.h"

TEST(ContiguousContainer, CheckIfExists) {
    ContiguousContainer<int> ccnt;

    ASSERT_EQ(ccnt.size(), 0);
}

TEST(ContiguousContainer, PushBack) {
    ContiguousContainer<int> ccnt;
    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    ccnt.push_back(20);

    int lastElemIdx = ccnt.size() - 1;
    int lastElem = ccnt[lastElemIdx];

    ASSERT_EQ(lastElem, 20);
}

TEST(ContiguousContainer, PushStart) {
    ContiguousContainer<int> ccnt;
    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    ccnt.insert(0, 20);

    int firstElemIdx = 0;
    int firstElem = ccnt[firstElemIdx];

    ASSERT_EQ(firstElem, 20);

}

TEST(ContiguousContainer, PushMiddle) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int middleElemIdx = ccnt.size() / 2;
    ccnt.insert(middleElemIdx, 20);
    int middleElem = ccnt[middleElemIdx];

    ASSERT_EQ(middleElem, 20);

}

TEST(ContiguousContainer, PopBack) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int lastElemIdxPreErase = ccnt.size() - 1;
    ccnt.erase(lastElemIdxPreErase);
    int lastElemIdxPostErase = ccnt.size() - 1;
    int lastElem = ccnt[lastElemIdxPostErase];

    ASSERT_EQ(lastElem, 8);

}

TEST(ContiguousContainer, PopStart) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int firstElemIdx = 0;
    ccnt.erase(firstElemIdx);
    int lastElem = ccnt[firstElemIdx];

    ASSERT_EQ(lastElem, 1);
}

TEST(ContiguousContainer, PopMiddle) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int middleElemIdx = ccnt.size() / 2;
    ccnt.erase(middleElemIdx);
    int middleElem = ccnt[middleElemIdx];

    ASSERT_EQ(middleElem, 6);
}

TEST(ContiguousContainer, GetElement) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

    int want = 2;
    int got = ccnt[2];

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
