//
// Created by Admin on 29.05.2024.
//

#include "gtest/gtest.h"
#include "../Set.h"

TEST(SetTest, ConstructorDefault){
    Set<int> set;
    ASSERT_EQ(set.size(), 0);
}

TEST(SetTest, InsertSingleElement){
    Set<int> set;
    set.insert(1);
    ASSERT_EQ(set.size(), 1);
}

TEST(SetTest, InsertDuplicateElement){
    Set<int> set;
    set.insert(1);
    set.insert(1);
    ASSERT_EQ(set.size(), 1);
}

TEST(SetTest, RemoveExistingElement){
    Set<int> set;
    set.insert(1);
    set.remove(1);
    ASSERT_EQ(set.size(), 0);
}

TEST(SetTest, RemoveNonExistingElement){
    Set<int> set;
    set.remove(1);
    ASSERT_EQ(set.size(), 0);
}

TEST(SetTest, ContainsExistingElement){
    Set<int> set;
    set.insert(1);
    ASSERT_TRUE(set.contains(1));
}

TEST(SetTest, ContainsNonExistingElement){
    Set<int> set;
    ASSERT_FALSE(set.contains(1));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}