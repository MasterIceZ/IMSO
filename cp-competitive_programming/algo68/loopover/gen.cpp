#include "testlib.h"
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>

//-------------- Options ----------------
int num_move;
int n;
//---------------------------------------

struct IGenerator {
  virtual ~IGenerator() = default;
  virtual void run() = 0;
};

struct Generator : IGenerator {
  Generator() {}
  void run() override {
    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        grid[i][j] = n * i + j + 1;
      }
    }

    int moves_left = num_move;
    while (moves_left > 0) {
      bool is_row = rnd.next(0, 1);
      int idx = rnd.next(0, n - 1);
      
      int max_shift = std::min(moves_left, n - 1);
      
      int head = rnd.next(1, max_shift);
      if (is_row) {
        std::rotate(grid[idx].begin(), grid[idx].begin() + (n - head), grid[idx].end());
      } else {
        std::vector<int> shifted(n);
        for (int j = 0; j < n; j++) {
          shifted[(j + head) % n] = grid[j][idx];
        }
        for (int j = 0; j < n; j++) {
          grid[j][idx] = shifted[j];
        }
      }
      
      moves_left -= head;
    }

    std::cout << n << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cout << grid[i][j] << " \n"[j == n - 1];
      }
    }
  }
};

int main(int argc, char *argv[]) {
  std::cout << std::fixed << std::setprecision(2);

  registerGen(argc, argv, 1);
  n = opt<int>("n");
  num_move = opt<int>("num_move");
  std::string _ = opt<std::string>("temp", "");
  
  IGenerator *generator = new Generator();
  generator->run();
  delete generator;

  return 0;
}
