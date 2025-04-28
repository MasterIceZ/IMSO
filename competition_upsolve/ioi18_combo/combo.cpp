#include "combo.h"
#include <string>

void solve_for_one(std::string &answer, std::string &other) {
if(press("AB")) {
    if(press("A")) {
      answer = "A";
      other = "BXY";
    }
    else {
      answer = "B";
      other = "AXY";
    }
  }
  else {
    if(press("X")) {
      answer = "X";
      other = "ABY";
    }
    else {
      answer = "Y";
      other = "ABX";
    }
  }
}

std::string guess_sequence(int N) {
  std::string answer, other;
  solve_for_one(answer, other);
  if(N == 1) {
    return answer;
  }
  while((int) answer.size() + 1< N) {
    std::string to_try = answer + other[0] + answer + other[1] + other[0] + answer + other[1] + other[1] + answer + other[1] + other[2];
    int p = press(to_try);
    if((int) answer.size() + 1 == p) {
      answer = answer + other[0];
    }
    else if((int) answer.size() + 2 == p) {
      answer = answer + other[1];
    }
    else {
      answer = answer + other[2];
    }
  }
  if((int) answer.size() != press(answer + other[0])) {
    answer += other[0];
  }
  else if((int) answer.size() != press(answer + other[1])) {
    answer += other[1];
  }
  else {
    answer += other[2];
  }
  return answer;
}
