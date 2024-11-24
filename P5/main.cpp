#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <bitset>

constexpr size_t MAX_N = 4000;

struct BinaryMatrix {
  size_t n;
  std::bitset<MAX_N> data[MAX_N];

  BinaryMatrix(std::istream& is, size_t n)
      : n(n)
  {
    std::string hex_str;

    for (size_t row = 0; row < n; ++row) {
      std::cin >> hex_str;
      size_t col = 0;

      for (char c : hex_str) {
        setElement(row, col, c);
        col += 4;
      }
    }
  }

  void setElement(size_t row, size_t col, char value) {
    value = value >= 'A' ? value - 'A' + 10 : value - '0';
    for (size_t i = 3; i <= 3; i--) {
      data[row][col + (3 - i)] = (value >> i) & 1;
    }
  }

  bool getElement(size_t row, size_t col) const {
    return data[row][col];
  }

  void print(std::ostream& os) const {
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        os << getElement(i, j);
      }
      os << '\n';
    }
  }
};

std::bitset<MAX_N> multiplyMatrixVector(const BinaryMatrix& matrix, const std::bitset<MAX_N>& vec) {
  std::bitset<MAX_N> result;
  for (size_t i = 0; i < matrix.n; ++i) {
    result[i] = (matrix.data[i] & vec).count() & 1;
  }
  return result;
}

bool check(const BinaryMatrix& A, const BinaryMatrix& B, const BinaryMatrix& C) {
  std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<int> dist(0, 1);

  for (int iter = 0; iter < 100; ++iter) {
    std::bitset<MAX_N> v(A.n);
    for (size_t i = 0; i < A.n; ++i) {
      v[i] = dist(rng);
    }

    std::bitset<MAX_N> abv = multiplyMatrixVector(A, multiplyMatrixVector(B, v));
    std::bitset<MAX_N> cv = multiplyMatrixVector(C, v);

    if (abv != cv) {
      return false;
    }
  }
  return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  size_t n;
  std::cin >> n;

  BinaryMatrix A(std::cin, n), B(std::cin, n), C(std::cin, n);

  if (check(A, B, C)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }

  return 0;
}