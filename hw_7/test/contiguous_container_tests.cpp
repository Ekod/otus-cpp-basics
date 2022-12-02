#include "gtest/gtest.h"
#include "../src/contiguous.h"

TEST(ContiguousContainer, CheckIfExists) {
    ContiguousContainer<int> ccnt;

    ASSERT_EQ(ccnt.size(), 0);
}

TEST(ContiguousContainer, PushBack) {
    ContiguousContainer<int> ccnt;

}

TEST(ContiguousContainer, PushStart) {
    ContiguousContainer<int> ccnt;
    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

}

TEST(ContiguousContainer, PushMiddle) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

}

TEST(ContiguousContainer, PopBack) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

}

TEST(ContiguousContainer, PopStart) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }


}

TEST(ContiguousContainer, PopMiddle) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }


}

TEST(ContiguousContainer, GetElement) {
    ContiguousContainer<int> ccnt;

    for (int i = 0; i < 10; i++) {
        ccnt.push_back(i);
    }

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

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
