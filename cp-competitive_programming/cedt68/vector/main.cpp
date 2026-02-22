#include <iomanip>
#include <iostream>
#include "compressed_vector.h"
#include "student.h"

int main() {
  std::cout << std::fixed << std::setprecision(2);

  size_t cap;
  std::cin >> cap;
  CP::CompressedVector<int> cv(cap);
  std::string cmd;
  while (true) {
    std::cin >> cmd;
    if (cmd == "sz") {
      std::cout << cv.size() << "\n";
    } else if (cmd == "ac") {
      int pos;
      std::cin >> pos;
      std::cout << cv[pos] << "\n";
    } else if (cmd == "in") {
      int pos, x;
      std::cin >> pos >> x;
      cv.insert(pos, x);
    } else if (cmd == "po") {
      cv.pop_back();
    } else if (cmd == "q") {
      break;
    }
  }
  std::cout << "Final Capacity: " << cv.capacity() << "\n";
  std::cout << "Final Size: " << cv.size() << "\n";
  std::cout << "Final Vector: ";
  cv.print_vector();

  return 0;
}
