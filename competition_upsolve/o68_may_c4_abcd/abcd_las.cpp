#include <chrono>
#include <random>
#include <vector>

#include "abcd.h"

const char L[] = "ABCD";
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline int rnd(int hi) {
  return std::uniform_int_distribution<int>(0, hi - 1)(rng);
}

std::vector<char> abcd(int N) {
  std::vector<char> asking(N);
  for(char &c: asking) {
    c = L[rnd(4)];
  }
  int score = exam(asking);

  std::vector<char> order(N);
  for(int i = 0; i < N; ++i) {
    order[i] = i;
  }

  int query_count = 4 * N;
  while(score < N && query_count > 0) {
    bool do_something = false;
    std::shuffle(order.begin(), order.end(), rng);

    for(auto i: order) {
      char prev = asking[i];
      if(prev == 'A' || prev == 'B' || prev == 'C' || prev == 'D') {
        continue;
      }

      std::vector<char> candidates = {'A', 'B', 'C', 'D'};
      auto it = std::find(candidates.begin(), candidates.end(), prev);
      candidates.erase(it);
      std::shuffle(candidates.begin(), candidates.end(), rng);

      for(auto c: candidates) {
        asking[i] = c;
        int new_score = exam(asking);
        query_count--;
        if(new_score > score) {
          score = new_score;
          do_something = true;
          break;
        }
        if(new_score < score) {
          asking[i] = prev;
          prev = 'X';
          break;
        }
      }
      if(prev != 'X' && asking[i] != prev) {
        asking[i] = prev;
      }
    }
    if(!do_something) {
      for(int i = 0; i < N; ++i) {
        if(asking[i] == 'A' || asking[i] == 'B' || asking[i] == 'C' || asking[i] == 'D') {
          continue;
        }
        asking[i] = L[rnd(4)];
      }
      score = exam(asking);
      query_count--;
    }
  }
  return asking;
}
