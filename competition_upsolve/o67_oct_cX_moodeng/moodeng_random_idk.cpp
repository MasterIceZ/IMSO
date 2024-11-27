#include "moodeng.h"
#include <bits/stdc++.h>

using namespace std;
using table_t = vector<vector<bool>>;

int n, m;

table_t get_table(int x, int y) {
  table_t table(n, vector<bool>(m));
  table[x][y] = true;
  return table;
}

void search(int N, int M) {
  n = N;
  m = M;
  srand(10);
  while(true) {
    int x = rand() % N;
    int y = rand() % M;
    if(query(get_table(x, y))) {
      return ;
    }
  }
}