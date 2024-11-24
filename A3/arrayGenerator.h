#include <vector>
#include <random>
#include <algorithm>

#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H

class ArrayGenerator {
public:
  ArrayGenerator(int max_size = 10000, int max_value = 6000) :
    max_size_(max_size),
    max_value_(max_value),
    random_array_(generateRandomArray()),
    sorted_array_(generateSortedArray()),
    almost_sorted_array_(generateAlmostSortedArray()) {}

  std::vector<int> getRandomArray(size_t size) const {
    return {random_array_.begin(), random_array_.begin() + size};
  }

  std::vector<int> getSortedArray(size_t size) const {
    return {sorted_array_.begin(), sorted_array_.begin() + size};
  }

  std::vector<int> getAlmostSortedArray(size_t size) const {
    return {almost_sorted_array_.begin(), almost_sorted_array_.begin() + size};
  }

  std::vector<int> generate(size_t n, size_t type) {
    if (type == 0) {
      return getRandomArray(n);
    } else if (type == 1) {
      return getSortedArray(n);
    } else {
      return getAlmostSortedArray(n);
    }
  }

private:
  int max_size_;
  int max_value_;
  std::vector<int> random_array_;
  std::vector<int> sorted_array_;
  std::vector<int> almost_sorted_array_;

  std::vector<int> generateRandomArray() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, max_value_);

    std::vector<int> array(max_size_);
    std::generate(array.begin(), array.end(), [&]() { return distrib(gen); });
    return array;
  }

  std::vector<int> generateSortedArray() const {
    std::vector<int> array = random_array_;
    std::sort(array.begin(), array.end(), std::greater<int>());
    return array;
  }

  std::vector<int> generateAlmostSortedArray() const {
    std::vector<int> array = sorted_array_;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, max_size_ - 1);

    int swap_count = max_size_ / 100; // Меняем 1% элементов
    for (int i = 0; i < swap_count; ++i) {
      int index1 = distrib(gen);
      int index2 = distrib(gen);
      std::swap(array[index1], array[index2]);
    }

    return array;
  }
};

#endif //ARRAYGENERATOR_H
