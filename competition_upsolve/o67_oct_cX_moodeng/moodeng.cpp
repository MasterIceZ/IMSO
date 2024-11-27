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
  int mm = max(M - 1, 1);
  for(int i=1; i<mm; ++i) {
    if(query(get_table(0, i))) {
      return ;
    }
  }
  for(int i=mm-1; i>=1; --i) {
    if(query(get_table(0, i))) {
      return ;
    }
  }
}