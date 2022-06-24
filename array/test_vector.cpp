
#include <gtest/gtest.h>

#include "vector.hpp"

const int INITIAL_CAPACITY{5};

TEST(Vector, Constructor) {
  ads::Vector<int> vector(INITIAL_CAPACITY);
  EXPECT_EQ(vector.get_size(), 0);
  EXPECT_EQ(vector.get_capacity(), INITIAL_CAPACITY);
  EXPECT_EQ(vector.get_is_empty(), true);

  EXPECT_DEATH(ads::Vector<int> vector2(0),
               "Error: initialCapacity must be greater than 0");
}

TEST(Vector, Push) {
  ads::Vector<int> vector;
  vector.push(10);
  vector.push(20);
  vector.push(30);
  EXPECT_EQ(vector.get_size(), 3);
  EXPECT_EQ(vector.get_is_empty(), false);
  EXPECT_EQ(vector.get_item(0), 10);
  EXPECT_EQ(vector.get_item(1), 20);
  EXPECT_EQ(vector.get_item(2), 30);
}

TEST(Vector, Pop) {
  ads::Vector<int> vector;
  vector.push(10);
  vector.push(20);
  vector.push(30);
  EXPECT_EQ(vector.pop(), 30);
  EXPECT_EQ(vector.pop(), 20);
  EXPECT_EQ(vector.pop(), 10);
  EXPECT_EQ(vector.get_size(), 0);
  EXPECT_EQ(vector.get_is_empty(), true);

  EXPECT_DEATH(vector.pop(), "Error: List is empty");
}

TEST(Vector, Resize) {
  ads::Vector<int> vector(INITIAL_CAPACITY);

  int cap_before_size_up = vector.get_capacity();
  for (int i = 0; i < 6; i++) vector.push(i);
  int cap_after_size_up = vector.get_capacity();
  EXPECT_EQ(cap_after_size_up, cap_before_size_up * 2);

  for (int i = 0; i < 5; ++i) vector.pop();
  int cap_after_size_down = vector.get_capacity();
  EXPECT_EQ(cap_after_size_down, cap_after_size_up / 2);
}

TEST(Vector, Insert) {
  ads::Vector<int> vector;
  vector.push(10);
  vector.push(20);
  vector.push(30);
  vector.insert(0, 40);
  EXPECT_EQ(vector.get_item(0), 40);
  vector.insert(3, 50);
  EXPECT_EQ(vector.get_item(3), 50);
}

TEST(Vector, Remove) {
  ads::Vector<int> vector;
  vector.push(10);
  vector.push(20);
  vector.push(30);
  vector.remove_by_index(1);
  EXPECT_DEATH(vector.find_item(20), "Error: Item not found");

  ads::Vector<int> vector2;
  vector2.push(10);
  vector2.push(20);
  vector2.push(30);
  vector2.remove_by_value(20);
  EXPECT_DEATH(vector2.find_item(20), "Error: Item not found");

  EXPECT_DEATH(vector.remove_by_index(5), "Error: Index out of range");
  EXPECT_DEATH(vector.remove_by_value(40), "Error: Item not found");
}