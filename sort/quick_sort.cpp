#include <utility>

#include "sort.hpp"
namespace ads {

namespace detail {

void fisher_yates_shuffle(int arr[], int size) {
  srand(time(NULL));
  for (int i = size - 1; i > 0; --i) {
    int target = rand() % (i + 1);
    std::swap(arr[i], arr[target]);
  }
}

int partition(int arr[], int lo, int hi) {
  int i = lo;
  int j = hi + 1;

  while (1) {
    while (arr[++i] < arr[lo]) {
      if (hi < i) break;
    }
    while (arr[lo] < arr[--j]) {
      if (j < lo) break;
    }

    if (i >= j) break;
    std::swap(arr[i], arr[j]);
  }
  std::swap(arr[lo], arr[j]);
  return j;
}

void quick_sort_recursion(int arr[], int lo, int hi) {
  if (hi <= lo) return;
  int j = partition(arr, lo, hi);
  quick_sort_recursion(arr, lo, j - 1);
  quick_sort_recursion(arr, j + 1, hi);
}

}  // namespace detail

void quick_sort(int arr[], int length) {
  detail::fisher_yates_shuffle(arr, length);
  // for (int i = 0; i < length; i++) printf("%d, \n", arr[i]);
  detail::quick_sort_recursion(arr, 0, length - 1);
  // for (int i = 0; i < length; i++) printf("%d, \n", arr[i]);
}

}  // namespace ads