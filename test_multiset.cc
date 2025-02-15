#include <gtest/gtest.h>
#include <multiset.h>

TEST(Multiset, Empty) {
    Multiset<int> mset;
    EXPECT_TRUE(mset.Empty());
    EXPECT_EQ(mset.Size(), 0);
    EXPECT_THROW(mset.Min(), std::runtime_error);
    EXPECT_THROW(mset.Max(), std::runtime_error);
    EXPECT_THROW(mset.Remove(42), std::runtime_error);
    EXPECT_THROW(mset.Count(42), std::runtime_error);
}

TEST(Multiset, InsertSingleElement) {
    Multiset<int> mset;
    mset.Insert(10);
    EXPECT_FALSE(mset.Empty());
    EXPECT_EQ(mset.Size(), 1);
    EXPECT_EQ(mset.Min(), 10);
    EXPECT_EQ(mset.Max(), 10);
    EXPECT_EQ(mset.Count(10), 1);
}

TEST(Multiset, InsertMultipleUniqueElements) {
    Multiset<int> mset;
    mset.Insert(5);
    mset.Insert(10);
    mset.Insert(20);
    EXPECT_EQ(mset.Size(), 3);
    EXPECT_EQ(mset.Min(), 5);
    EXPECT_EQ(mset.Max(), 20);
    EXPECT_EQ(mset.Count(10), 1);
}

TEST(Multiset, InsertDuplicates) {
    Multiset<int> mset;
    mset.Insert(15);
    mset.Insert(15);
    mset.Insert(15);
    mset.Insert(10);
    mset.Insert(20);
    EXPECT_EQ(mset.Size(), 5);
    EXPECT_EQ(mset.Count(15), 3);
    EXPECT_EQ(mset.Min(), 10);
    EXPECT_EQ(mset.Max(), 20);
}

TEST(Multiset, RemoveSingleElement) {
    Multiset<int> mset;
    mset.Insert(10);
    mset.Remove(10);
    EXPECT_TRUE(mset.Empty());
    EXPECT_EQ(mset.Size(), 0);
}

TEST(Multiset, RemoveOneInstanceOfDuplicate) {
    Multiset<int> mset;
    mset.Insert(5);
    mset.Insert(5);
    mset.Remove(5);
    EXPECT_EQ(mset.Size(), 1);
    EXPECT_EQ(mset.Count(5), 1);
}

TEST(Multiset, RemoveAllInstancesOfDuplicate) {
    Multiset<int> mset;
    mset.Insert(3);
    mset.Insert(3);
    mset.Insert(3);
    mset.Remove(3);
    mset.Remove(3);
    mset.Remove(3);
    EXPECT_TRUE(mset.Empty());
}

TEST(Multiset, RemoveNonExistentElement) {
    Multiset<int> mset;
    mset.Insert(10);
    EXPECT_THROW(mset.Remove(42), std::runtime_error);
}

TEST(Multiset, FloorFunction) {
    Multiset<int> mset;
    mset.Insert(5);
    mset.Insert(10);
    mset.Insert(15);
    EXPECT_EQ(mset.Floor(12), 10);
    EXPECT_EQ(mset.Floor(15), 15);
    EXPECT_EQ(mset.Floor(4), std::runtime_error);
}

TEST(Multiset, CeilFunction) {
    Multiset<int> mset;
    mset.Insert(5);
    mset.Insert(10);
    mset.Insert(15);
    EXPECT_EQ(mset.Ceil(12), 15);
    EXPECT_EQ(mset.Ceil(10), 10);
    EXPECT_THROW(mset.Ceil(16), std::runtime_error);
}

TEST(Multiset, MixedOperations) {
    Multiset<int> mset;
    mset.Insert(7);
    mset.Insert(3);
    mset.Insert(5);
    mset.Insert(3);
    mset.Remove(3);
    EXPECT_EQ(mset.Count(3), 1);
    EXPECT_EQ(mset.Size(), 3);
    EXPECT_EQ(mset.Min(), 3);
    EXPECT_EQ(mset.Max(), 7);
}

TEST(Multiset, InsertDescendingOrder) {
    Multiset<int> mset;
    for (int i = 10; i > 0; --i) {
        mset.Insert(i);
    }
    EXPECT_EQ(mset.Min(), 1);
    EXPECT_EQ(mset.Max(), 10);
}

TEST(Multiset, InsertAscendingOrder) {
    Multiset<int> mset;
    for (int i = 1; i <= 10; ++i) {
        mset.Insert(i);
    }
    EXPECT_EQ(mset.Min(), 1);
    EXPECT_EQ(mset.Max(), 10);
}

TEST(Multiset, RemoveRoot) {
    Multiset<int> mset;
    mset.Insert(20);
    mset.Insert(10);
    mset.Insert(30);
    mset.Remove(20);
    EXPECT_EQ(mset.Min(), 10);
    EXPECT_EQ(mset.Max(), 30);
}

TEST(Multiset, LargeSetPerformance) {
    Multiset<int> mset;
    for (int i = 1; i <= 1000; i++) {
        mset.Insert(i);
    }
    EXPECT_EQ(mset.Size(), 1000);
    EXPECT_EQ(mset.Min(), 1);
    EXPECT_EQ(mset.Max(), 1000);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
