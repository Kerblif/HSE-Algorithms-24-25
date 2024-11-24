#include <functional>
#include <iostream>
#include <vector>

#ifndef SORT_H
#define SORT_H

typedef std::function<void(std::vector<int>&, size_t, size_t)> SortFunction;

static void insertionSort(std::vector<int>& arr, size_t left, size_t right) {
  for (size_t i = left + 1; i <= right; ++i) {
    int key = arr[i];
    size_t j = i - 1;

    while (j >= left && arr[j] > key && j <= right) {
      arr[j + 1] = arr[j];
      --j;
    }

    arr[j + 1] = key;
  }
}

static void merge(std::vector<int>& arr, size_t left, size_t mid, size_t right) {
  size_t n1 = mid >= left ? mid - left + 1 : 0;
  size_t n2 = right >= mid ? right - mid : 0;

  std::vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; ++i) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; ++j) {
    R[j] = arr[mid + 1 + j];
  }

  size_t i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      ++i;
    } else {
      arr[k] = R[j];
      ++j;
    }
    ++k;
  }

  while (i < n1) {
    arr[k] = L[i];
    ++i;
    ++k;
  }

  while (j < n2) {
    arr[k] = R[j];
    ++j;
    ++k;
  }
}

void mergeSort(std::vector<int>& arr, size_t left, size_t right) {
  if (left < right && right < arr.size()) {
    size_t mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

void mergeInsertionSort(std::vector<int>& arr, size_t left, size_t right, size_t threshold) {
  if (left < right && right < arr.size()) {
    if (right - left <= threshold) {
      insertionSort(arr, left, right);
    } else {
      size_t mid = left + (right - left) / 2;
      mergeInsertionSort(arr, left, mid, threshold);
      mergeInsertionSort(arr, mid + 1, right, threshold);
      merge(arr, left, mid, right);
    }
  }
}

SortFunction mergeInsertionSortCreator(size_t threshold) {
  return [threshold](std::vector<int>& arr, size_t left, size_t right) {
    mergeInsertionSort(arr, left, right, threshold);
  };
}

#endif //SORT_H