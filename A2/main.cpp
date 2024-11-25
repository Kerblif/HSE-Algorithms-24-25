#include <iostream>
#include <vector>
#include "sortTester.h"

int main() {
  SortTester mergeSortTester("./merge.txt");
  SortTester mergeInsertionSort5("./m+i-5.txt");
  SortTester mergeInsertionSort10("./m+i-10.txt");
  SortTester mergeInsertionSort20("./m+i-20.txt");
  SortTester mergeInsertionSort30("./m+i-30.txt");
  SortTester mergeInsertionSort50("./m+i-50.txt");
  SortTester mergeInsertionSort100("./m+i-100.txt");
  SortTester mergeInsertionSort200("./m+i-200.txt");
  SortTester mergeInsertionSort300("./m+i-300.txt");
  SortTester mergeInsertionSort400("./m+i-400.txt");

  mergeSortTester.TestSortWithLogs(mergeSort);
  mergeInsertionSort5.TestSortWithLogs(mergeInsertionSortCreator(5));
  mergeInsertionSort10.TestSortWithLogs(mergeInsertionSortCreator(10));
  mergeInsertionSort20.TestSortWithLogs(mergeInsertionSortCreator(20));
  mergeInsertionSort30.TestSortWithLogs(mergeInsertionSortCreator(30));
  mergeInsertionSort50.TestSortWithLogs(mergeInsertionSortCreator(50));
  mergeInsertionSort100.TestSortWithLogs(mergeInsertionSortCreator(100));
  mergeInsertionSort200.TestSortWithLogs(mergeInsertionSortCreator(200));
  mergeInsertionSort300.TestSortWithLogs(mergeInsertionSortCreator(300));
  mergeInsertionSort400.TestSortWithLogs(mergeInsertionSortCreator(400));

  for (size_t type = 0; type < 3; ++type) {
    double mergeTime = mergeSortTester.TestSort(mergeSort, 10000, type);

    double mergeInsertionTime = 0;
    size_t limit = 4;

    while (mergeInsertionTime < mergeTime) {
      mergeInsertionTime = mergeSortTester.TestSort(mergeInsertionSortCreator(++limit), 10000, type);
    }

    std::cout << type << " " << limit << std::endl;
  }
}