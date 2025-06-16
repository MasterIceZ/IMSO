#include <algorithm>
#include <chrono>
#include <random>
#include <utility>
#include <vector>

#include "abcd.h"

const char L[] = "ABCD";

std::vector<char> abcd(int N) {

  std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> rand_pos(0, N - 1);
  std::uniform_int_distribution<int> rand_letter(0, 3);

  std::vector<char> answer(N, 'A');
  for(int i=0; i<N; ++i) {
    answer[i] = L[rand_letter(rng)];
  }
  int score = exam(answer);

  while(score < N) {
    bool better = false;
    for(int t=0; t<N; ++t) {
      int i = rand_pos(rng);
      char prev = answer[i];
      char cand;
      do {
        cand = L[rand_letter(rng)];
      } while(cand == prev);
      
      answer[i] = cand;
      int new_score = exam(answer);
      if(new_score >= score) {
        score = new_score;
        better = true;
        break;
      }
      else {
        answer[i] = prev;
      }
    }
    if(!better) {
      for(int i=0; i<N; ++i) {
        answer[i] = L[rand_letter(rng)];
      }
      score = exam(answer);
    }
  }
  return answer;
}
