#include <gtest/gtest.h>

#include "bst.hpp"

TEST(BstTest, Insert) {
  ads::Bst<int> bst;
  bst.insert(32);
  bst.insert(22);
  bst.insert(111);
  bst.insert(63);
  bst.insert(58);
  bst.insert(221);
  // bst.print_dfs();
  // bst.print_bfs();
  EXPECT_EQ(bst.get_min(), 22);
  EXPECT_EQ(bst.get_height(), 2);
}

TEST(BstTest, Remove) {
  ads::Bst<int> bst;
  bst.insert(32);
  bst.insert(22);
  bst.insert(111);
  bst.insert(63);
  bst.insert(58);
  bst.insert(221);
  bst.remove(111);
  // bst.print_dfs();
  EXPECT_EQ(bst.get_min(), 22);
}

TEST(BstTest, Search) {
  ads::Bst<int> bst;
  bst.insert(32);
  bst.insert(22);
  bst.insert(111);
  bst.insert(63);
  bst.insert(58);
  bst.insert(221);
  EXPECT_EQ(bst.search(111), true);
  EXPECT_EQ(bst.search(333), false);
}

TEST(BstTest, GetIsBst) {
  ads::Bst<int> bst;
  bst.insert(32);
  bst.insert(22);
  bst.insert(111);
  bst.insert(63);
  bst.insert(58);
  bst.insert(221);
  EXPECT_EQ(bst.get_is_bst(), true);
  bst.insert(111);
  EXPECT_EQ(bst.get_is_bst(), false);
}

TEST(BstTest, PrintBFS) {
  ads::Bst<int> bst;
  bst.insert(32);
  bst.insert(22);
  bst.insert(111);
  bst.insert(63);
  bst.insert(58);
  bst.insert(221);
  // bst.print_bfs();
}