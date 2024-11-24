#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

struct Solution {
  std::vector<int> positions;
  size_t n;

  Solution(size_t n) : n(n), positions(n) {
    for (size_t i = 0; i < n; ++i) {
      positions[i] = i;
    }
  }

  bool areAttacking(int q1, int q2) const {
    return positions[q1] == positions[q2] ||
           std::abs(q1 - q2) == std::abs(positions[q1] - positions[q2]);
  }

  int countAttacks() const {
    int attacks = 0;
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = i + 1; j < n; ++j) {
        attacks += areAttacking(i, j);
      }
    }
    return attacks;
  }

  void print(std::ostream& os) const {
    for (size_t i = 0; i < n; ++i) {
      os << positions[i] + 1 << " ";
    }
    os << std::endl;
  }
};

Solution solveNQueens(size_t n) {
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_int_distribution<size_t> dist(0, n - 1);
  std::uniform_real_distribution<double> real_dist(0, 1);

  Solution solution(n);
  double temperature = n;
  int current_attacks = solution.countAttacks();

  while (current_attacks > 0) {
    size_t q1 = dist(rng);
    size_t q2 = dist(rng);

    if (q1 == q2) continue;

    std::swap(solution.positions[q1], solution.positions[q2]);
    int new_attacks = solution.countAttacks();
    int delta = new_attacks - current_attacks;

    if (delta <= 0 || std::exp(-delta / temperature) > real_dist(rng)) {
      current_attacks = new_attacks;
    } else {
      std::swap(solution.positions[q1], solution.positions[q2]);
    }

    temperature *= 0.999;
  }

  return solution;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  size_t n;
  std::cin >> n;

  solveNQueens(n).print(std::cout);

  return 0;
}