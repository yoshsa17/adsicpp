#include "sort.hpp"

namespace ads {
namespace detail {

void merge(int arr[], int const &lo, int const &mid, int const &hi) {
  int temp[hi + 1];
  int i = lo;
  int j = mid + 1;
  int k;

  for (int k = lo; k <= hi; ++k) temp[k] = arr[k];

  for (k = lo; k <= hi; ++k) {
    if (i > mid)
      arr[k] = temp[j++];
    else if (j > hi)
      arr[k] = temp[i++];
    else if (temp[i] > temp[j])
      arr[k] = temp[j++];
    else
      arr[k] = temp[i++];
  }
}

void merge_sort_recursion(int arr[], int const &lo, int const &hi) {
  // std::cout << "Low: " << lo << " High: " << hi << std::endl;
  if (lo >= hi) return;

  int mid = lo + (hi - lo) / 2;

  merge_sort_recursion(arr, lo, mid);
  merge_sort_recursion(arr, mid + 1, hi);
  merge(arr, lo, mid, hi);
}

}  // namespace detail

void merge_sort(int arr[], int length) {
  detail::merge_sort_recursion(arr, 0, length - 1);
}

}  // namespace ads