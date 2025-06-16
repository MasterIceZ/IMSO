#include "abcd.h"

#include <algorithm>
#include <utility>
#include <vector>

struct state_t {
  char c;
  int cnt;
  
  state_t(char c, int cnt):
    c(c), cnt(cnt) {}
  bool operator<(const state_t &o) const {
    return cnt < o.cnt;
  }
};

std::vector<char> abcd(int N) {
  std::vector<char> all_a(N, 'A');
  int base_a = exam(all_a);
  std::vector<char> all_b(N, 'B');
  int base_b = exam(all_b);
  std::vector<char> all_c(N, 'C');
  int base_c = exam(all_c);
  int base_d = N - base_a - base_b - base_c;

  std::vector<state_t> f;
  f.emplace_back('A', base_a);
  f.emplace_back('B', base_b);
  f.emplace_back('C', base_c);
  f.emplace_back('D', base_d);

  std::sort(f.begin(), f.end());
  std::reverse(f.begin(), f.end());

  std::vector<char> answer(N, f[0].c);
  int cur_freq = f[0].cnt;
  for(int i=0; i<N; ++i) {
    answer[i] = f[1].c;
    int try_ask = exam(answer);
    if(try_ask > cur_freq) {
      cur_freq = try_ask;
      continue;
    }
    if(try_ask < cur_freq) {
      answer[i] = f[0].c;
      continue;
    }
    answer[i] = f[2].c;
    int try_ask2 = exam(answer);
    if(try_ask2 > cur_freq) {
      cur_freq = try_ask2;
      continue;
    }
    answer[i] = f[3].c;
    cur_freq = cur_freq + 1;
  }

  return answer;
}
