#include <iostream>
#include <vector>
#include "sort.h"

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  size_t n;
  std::cin >> n;

  std::vector<int> arr(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  mergeInsertionSort(arr, 0, n-1);

  for (size_t i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }

  return 0;
}