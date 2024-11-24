#include <iostream>
#include <vector>

void countingSort(std::vector<int>& A) {
  int min_element = A[0];
  int max_element = A[0];

  for (int i = 1; i < A.size(); i++) {
    if (A[i] > max_element) {
      max_element = A[i];
    }

    if (A[i] < min_element) {
      min_element = A[i];
    }
  }

  std::vector<int> count(max_element - min_element + 1, 0);

  for (const int &i : A) {
    count[i - min_element]++;
  }

  for (size_t i = 1; i <= max_element - min_element; i++) {
    count[i] += count[i - 1];
  }

  std::vector<int> output(A.size());

  for (size_t i = A.size() - 1; i != -1; i--) {
    output[count[A[i] - min_element] - 1] = A[i];
    count[A[i] - min_element]--;
  }

  A = output;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  size_t n;
  std::cin >> n;

  if (n == 0) {
    return 0;
  }

  std::vector<int> A(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  countingSort(A);

  for (size_t i = 0; i < n; i++) {
    std::cout << A[i] << " ";
  }

  return 0;
}