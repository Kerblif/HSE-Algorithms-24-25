#include <fstream>

#include "arrayGenerator.h"
#include "sort.h"

#ifndef SORTTESTER_H
#define SORTTESTER_H

class SortTester {
  private:
    ArrayGenerator array_generator_;
    std::ofstream out_;

  public:
    SortTester(std::string filename) {
      array_generator_ = ArrayGenerator();
      out_.open(filename);

      if (!out_.is_open()) {
        std::cerr << "Error opening file sort_test_results.txt" << std::endl;
        return;
      }
    }

    ~SortTester() {
      out_.close();
    }

    void TestSortWithLogs(SortFunction func) {
      for (size_t n = 500; n <= 10000; n += 100) {
        for (size_t type = 0; type < 3; ++type) {
          double time = 0;

          for (size_t i = 0; i < 10; ++i) {
            time += TestSort(func, n, type);
          }

          time /= 10;
          out_ << n << " " << type << " " << time << std::endl;
        }
      }
    }

    double TestSort(SortFunction func, size_t n, size_t type) {
      auto arr = array_generator_.generate(n, type);
      auto start = std::chrono::high_resolution_clock::now();
      func(arr, 0, n - 1);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

      return duration.count();
    }
};

#endif //SORTTESTER_H
