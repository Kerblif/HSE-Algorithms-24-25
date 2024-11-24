#include <iostream>
#include <vector>

void heapify(std::vector<int>& A, size_t n, size_t i) {
    size_t cur = i;
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;

    if (l < n && A[l] > A[cur]) {
        cur = l;
    }

    if (r < n && A[r] > A[cur]) {
        cur = r;
    }

    if (cur != i) {
        std::swap(A[i], A[cur]);
        heapify(A, n, cur);
    }
}

void buildMaxHeap(std::vector<int>& A) {
    size_t n = A.size();

    for (size_t i = n / 2 - 1; i < n; i--) {
        heapify(A, n, i);
    }
}

void heapSort(std::vector<int>& A) {
    size_t n = A.size();

    buildMaxHeap(A);

    for (size_t i = n - 1; i < n; i--) {
        std::swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;

    std::vector<int> A(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    heapSort(A);

    for (size_t i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }

    return 0;
}