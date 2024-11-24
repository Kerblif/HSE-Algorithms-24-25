#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "sort.h"
#include "sortTester.h"

int main() {
  SortTester quickSortTester("./quick.txt");
  quickSortTester.TestSortWithLogs(quickSort);

  SortTester introSortTester("./intro.txt");
  introSortTester.TestSortWithLogs(introSort);
}
