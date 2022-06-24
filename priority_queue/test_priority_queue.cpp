#include <gtest/gtest.h>

#include "priority_queue.hpp"

int INITIAL_CAPACITY = 20 + 1;

TEST(PriorityQueue, Insert) {
  ads::PriorityQueue<std::string> pq;
  pq.insert(4, "Task D");
  pq.insert(1, "Task A");
  pq.insert(5, "Task E");
  pq.insert(2, "Task B");
  pq.insert(3, "Task C");
  // pq.print();
  EXPECT_EQ(pq.get_max(), "Task A");
  EXPECT_EQ(pq.get_size(), 5);
  EXPECT_EQ(pq.get_capacity(), INITIAL_CAPACITY - 1);
}

TEST(PriorityQueue, ExtractMax) {
  ads::PriorityQueue<std::string> pq;
  pq.insert(320, "Task D");
  pq.insert(23, "Task A");
  pq.insert(400, "Task E");
  pq.insert(111, "Task B");
  pq.insert(280, "Task C");
  EXPECT_EQ(pq.get_max(), "Task A");
  EXPECT_EQ(pq.get_size(), 5);
  EXPECT_EQ(pq.extract_max(), "Task A");
  EXPECT_EQ(pq.extract_max(), "Task B");
  EXPECT_EQ(pq.extract_max(), "Task C");
  EXPECT_EQ(pq.extract_max(), "Task D");
  EXPECT_EQ(pq.extract_max(), "Task E");
  EXPECT_EQ(pq.get_size(), 0);
}

TEST(PriorityQueue, Remove) {
  ads::PriorityQueue<std::string> pq;
  EXPECT_DEATH(pq.remove_by_index(3), "Error: Queue is empty");
  pq.insert(4, "Task D");
  pq.insert(1, "Task A");
  pq.insert(5, "Task E");
  pq.insert(2, "Task B");
  pq.insert(3, "Task C");

  EXPECT_EQ(pq.get_size(), 5);
  pq.remove_by_index(1);
  EXPECT_EQ(pq.get_size(), 4);
  EXPECT_EQ(pq.get_max(), "Task B");
  pq.remove_by_index(1);
  EXPECT_EQ(pq.get_size(), 3);
  EXPECT_EQ(pq.get_max(), "Task C");
  EXPECT_DEATH(pq.remove_by_index(pq.get_size() + 1),
               "Error: Index is out of range");
}

TEST(PriorityQueue, ChangePriorityQueue) {
  ads::PriorityQueue<std::string> pq;
  pq.insert(4, "Task D");
  pq.insert(1, "Task A");
  pq.insert(5, "Task E");
  pq.insert(2, "Task B");
  pq.insert(3, "Task C");
  // pq.print();
  pq.change_priority(1, 10);
  // pq.print();
  EXPECT_EQ(pq.get_max(), "Task B");
  pq.change_priority(1, 5);
  // pq.print();
  EXPECT_EQ(pq.get_max(), "Task C");
  EXPECT_DEATH(pq.change_priority(6, 10), "Error: Index is out of range");
  EXPECT_DEATH(pq.change_priority(1, -1), "Error: Priority is out of range");
}
