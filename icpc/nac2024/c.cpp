#include<bits/stdc++.h>

using namespace std;

const int MxN = 200020;
const int MxK = 10;

int u[MxN], v[MxN], x[MxN], s[MxN], mem[MxK][MxK][2][2];
string e[MxN];
stack<int> val;
stack<char> opr;

int prio(char x) {
  if(x == 'x' || x == 'y' || x == '1' || x == '0') {
    return -999;
  }
  switch(x) {
    case '(':
      return -2;
    case ')':
      return -1;
    case '^':
      return 1;
    case '|':
      return 2;
    case '&':
      return 3;
    case '=':
      return 4;
    case '!':
      return 5;
  }
}

int make_cal(int a, int b, char x) {
  switch(x) {
  case '^':
    return a ^ b;
  case '|':
    return a | b;
  case '&':
    return a & b;
  case '=':
    return a == b;
  }
}

void pop_stack() {
  if(opr.top() == '!') {
    int c = val.top();
    val.pop();
    val.emplace(!c);
  }
  else {
    int rhs = val.top();
    val.pop();
    int lhs = val.top();
    val.pop();
    int new_val = make_cal(lhs, rhs, opr.top());
    val.emplace(new_val);
  }
  opr.pop();
}

int calculate_expression(string _e, int x, int y) {
  while(!val.empty()) {
    val.pop();
  }
  while(!opr.empty()) {
    opr.pop();
  }
  for(auto e: _e) {
    if(prio(e) == -999) {
      if(isalpha(e)) {
        val.emplace(e == 'x' ? x: y);
      }
      else {
        val.emplace(e - '0');
      }
    }
    else if(e == '(') {
      opr.emplace('(');
    }
    else if(e == ')') {
      while(!opr.empty() && opr.top() != '(') {
        pop_stack();
      }
      opr.pop();
    }
    else {
      while(!opr.empty() && prio(opr.top()) >= prio(e)) {
        pop_stack();
      }
      opr.emplace(e);
    }
  }
  while(!opr.empty()) {
    pop_stack();
  }
  assert((int) val.size() == 1);
  return val.top();
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
//  int n, k;
//  cin >> n >> k;
//  for(int i=0; i<n; ++i) {
//    cin >> u[i] >> v[i] >> e[i] >> s[i];
//    u[i] -= 1;
//    v[i] -= 1;
//    for(int x=0; x<=1; ++x) {
//      for(int y=0; y<=1; ++y) {
//        if(calculate_expression(e[i], x, y) == 1) {
//          mem[u[i]][v[i]][x][y] = min(mem[u[i]][v[i]][x][y], i);
//        }
//      }
//    }
//  }
  cout << calculate_expression("x^y", 1, 1);
  return 0;
}
