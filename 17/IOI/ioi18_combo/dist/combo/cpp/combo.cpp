#include "combo.h"

std::string guess_sequence(int N) {
  std::string p = "";
  for (int i = 0; i < 4 * N; ++i) {
    p += 'A';
  }
  int coins = press(p);
  std::string S = "";
  for (int i = 0; i < N; ++i) {
    S += 'A';
  }
  return S;
}
