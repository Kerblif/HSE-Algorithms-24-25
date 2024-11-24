#include <iostream>
#include <vector>
#include <algorithm>

void radixSort(std::vector<int>& A) {
    size_t n = A.size();

    if (n == 0) return;

    int min_element = A[0];
    int max_element = A[0];

    for (size_t i = 1; i < n; i++) {
        max_element = std::max(max_element, A[i]);
        min_element = std::min(min_element, A[i]);
    }

    int offset = (min_element < 0) ? -min_element : 0;
    for (size_t i = 0; offset != 0 && i < n; i++) {
        A[i] += offset;
    }

    for (size_t exp = 1; max_element / exp > 0; exp *= 256) {
        std::vector<int> output(n);
        std::vector<int> count(256, 0);

        for (size_t i = 0; i < n; i++) {
            count[(A[i] / exp) % 256]++;
        }

        for (size_t i = 1; i < 256; i++) {
            count[i] += count[i - 1];
        }

        for (size_t i = n; i-- > 0;) {
            output[count[(A[i] / exp) % 256] - 1] = A[i];
            count[(A[i] / exp) % 256]--;
        }

        for (size_t i = 0; i < n; i++) {
            A[i] = output[i];
        }
    }

    for (size_t i = 0; offset != 0 && i < n; i++) {
        A[i] -= offset;
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

    radixSort(A);

    for (size_t i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }

    return 0;
}
