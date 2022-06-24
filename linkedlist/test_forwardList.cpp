#include <gtest/gtest.h>

#include "forwardList.hpp"

TEST(ForwardList, Constructor) {
  ads::ForwardList<int> list;
  EXPECT_DEATH(list.get_front(), "Error: List is empty");
  EXPECT_DEATH(list.get_back(), "Error: List is empty");
  EXPECT_DEATH(list.get_value(0), "Error: List is empty");
}

TEST(ForwardList, PushFront) {
  ads::ForwardList<int> list;
  list.push_front(10);
  list.push_front(20);
  EXPECT_EQ(list.get_front(), 20);
  EXPECT_EQ(list.get_back(), 10);
  EXPECT_EQ(list.get_value(0), 20);
  EXPECT_EQ(list.get_value(1), 10);
}

TEST(ForwardList, PopFront) {
  ads::ForwardList<int> list;
  list.push_front(10);
  list.push_front(20);
  EXPECT_EQ(list.pop_front(), 20);
  EXPECT_EQ(list.pop_front(), 10);
  EXPECT_DEATH(list.pop_front(), "Error: List is empty");
}

TEST(ForwardList, PushBack) {
  ads::ForwardList<int> list;
  list.push_back(10);
  list.push_back(20);
  EXPECT_EQ(list.get_front(), 10);
  EXPECT_EQ(list.get_back(), 20);
}

TEST(ForwardList, PopBack) {
  ads::ForwardList<int> list;
  list.push_front(10);
  list.push_front(20);
  EXPECT_EQ(list.pop_back(), 10);
  EXPECT_EQ(list.pop_back(), 20);
  EXPECT_DEATH(list.pop_back(), "Error: List is empty");
}

TEST(ForwardList, Insert) {
  ads::ForwardList<int> list;
  list.push_front(10);
  list.push_front(20);
  list.insert(1, 30);
  EXPECT_EQ(list.get_value(1), 30);

  ads::ForwardList<int> list2;
  list2.insert(0, 10);
  EXPECT_EQ(list2.get_front(), 10);
  list.insert(0, 40);
  EXPECT_EQ(list.get_front(), 40);

  ads::ForwardList<int> list3;
  EXPECT_DEATH(list3.insert(-1, 10), "Error: Index out of range");
  EXPECT_DEATH(list3.insert(1, 10), "Error: Index out of range");
}

TEST(ForwardList, RemoveByIndex) {
  ads::ForwardList<int> list;
  list.push_front(10);
  list.push_front(20);
  list.push_front(30);
  list.remove_by_index(1);
  EXPECT_EQ(list.get_value(1), 10);
}

TEST(ForwardList, RemoveByValue) {
  ads::ForwardList<int> list;
  list.push_front(10);
  list.push_front(20);
  list.push_front(30);
  list.remove_by_value(20);
  EXPECT_EQ(list.get_value(1), 10);
}

TEST(ForwardList, Reverse) {
  ads::ForwardList<int> list;
  list.push_front(10);
  list.push_front(20);
  list.push_front(30);
  // list.print();
  list.reverse();
  // list.print();
  EXPECT_EQ(list.get_front(), 10);
}