#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

constexpr size_t INSERTION_SORT_THRESHOLD = 16;

void insertionSort(std::vector<int>& arr, size_t left, size_t right) {
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

void heapify(std::vector<int>& A, size_t left, size_t n, size_t i) {
    size_t cur = i;
    size_t l = 2 * i + 1 + left;
    size_t r = 2 * i + 2 + left;

    if (l < n + left && A[l] > A[cur]) {
        cur = l;
    }

    if (r < n + left && A[r] > A[cur]) {
        cur = r;
    }

    if (cur != i) {
        std::swap(A[i], A[cur]);
        heapify(A, left, n, cur - left);
    }
}

void buildMaxHeap(std::vector<int>& A, size_t left, size_t right) {
    size_t n = right - left + 1;

    for (size_t i = n / 2 - 1; i < n; i--) {
        heapify(A, left, n, i);
    }
}

void heapSort(std::vector<int>& A, size_t left, size_t right) {
    size_t n = right - left + 1;

    buildMaxHeap(A, left, right);

    for (size_t i = n - 1; i < n; i--) {
        std::swap(A[left], A[i]);
        heapify(A, left, i, 0);
    }
}

void quickSort(std::vector<int>& arr, size_t left, size_t right, size_t depthLimit) {
    while (left < right) {
        if (depthLimit == 0) {
            heapSort(arr, left, right);
            return;
        }

        if (right - left + 1 <= INSERTION_SORT_THRESHOLD) {
            insertionSort(arr, left, right);
            return;
        }

        int pivot = arr[left + (right - left) / 2];
        size_t i = left, j = right;

        while (i <= j) {
            while (arr[i] < pivot) {
                ++i;
            }
            while (arr[j] > pivot) {
                --j;
            }
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                ++i;
                --j;
            }
        }

        if (j - left < right - i) {
            quickSort(arr, left, j, depthLimit - 1);
            left = i;
        } else {
            quickSort(arr, i, right, depthLimit - 1);
            right = j;
        }
    }
}

void introSort(std::vector<int>& arr, size_t left, size_t right) {
    if (left >= right) {
        return;
    }

    size_t depthLimit = 2 * static_cast<size_t>(std::log2(right - left + 1));
    quickSort(arr, left, right, depthLimit);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    introSort(arr, 0, n - 1);

    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
