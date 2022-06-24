#include <gtest/gtest.h>

#include "sort.hpp"

TEST(SortTest, MergeSort) {
  int arr[] = {5, 3, 1, 4, 2};
  ads::merge_sort(arr, 5);
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 2);
  EXPECT_EQ(arr[2], 3);
  EXPECT_EQ(arr[3], 4);
  EXPECT_EQ(arr[4], 5);
}

TEST(SortTest, QuickSort) {
  int arr[] = {5, 3, 1, 4, 2};
  ads::quick_sort(arr, 5);
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 2);
  EXPECT_EQ(arr[2], 3);
  EXPECT_EQ(arr[3], 4);
  EXPECT_EQ(arr[4], 5);
}
