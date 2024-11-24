#include <iostream>
#include <vector>
#include <algorithm>

struct Fraction {
  uint64_t numerator;
  uint64_t denominator;
  size_t index;
};

bool compareFractions(const Fraction& a, const Fraction& b) {
  const uint64_t v1 = a.numerator * b.denominator;
  const uint64_t v2 = b.numerator * a.denominator;

  if (v1 != v2) {
    return v1 < v2;
  }

  return a.index < b.index;
}

void stableSort(std::vector<Fraction>& fractions) {
  std::sort(fractions.begin(), fractions.end(), compareFractions);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  size_t n;
  std::cin >> n;

  std::vector<Fraction> fractions(n);
  for (size_t i = 0; i < n; ++i) {
    char slash;
    std::cin >> fractions[i].numerator >> slash >> fractions[i].denominator;
    fractions[i].index = i;
  }

  stableSort(fractions);

  for (const auto& fraction : fractions) {
    std::cout << fraction.numerator << "/" << fraction.denominator << " ";
  }

  return 0;
}
