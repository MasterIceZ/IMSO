#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 220;
const int UP = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int n, m;
char a[MxN][MxN];
bool visited[MxN][MxN];

int get_next_dir(int i, int j, int dir) {
  if(a[i][j] == '.') {
    return dir;
  }
  if(a[i][j] == '/') {
    switch(dir) {
      case UP:
        return RIGHT;
      case LEFT:
        return DOWN;
      case RIGHT:
        return UP;
      case DOWN:
        return LEFT;
    }
  }
  switch(dir) {
    case UP:
      return LEFT;
    case LEFT:
      return UP;
    case RIGHT:
      return DOWN;
    case DOWN:
      return RIGHT;
  }
}

bool ok(int stp_i, int stp_j, int dir) {
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      visited[i][j] = false;
    }
  }
  int cur_i = stp_i, cur_j = stp_j;
  while(1 <= cur_i && cur_i <= n && 1 <= cur_j && cur_j <= m) {
    visited[cur_i][cur_j] = true;
    dir = get_next_dir(cur_i, cur_j, dir);
    cur_i += di[dir];
    cur_j += dj[dir];
  }
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      if(a[i][j] == '.') {
        continue;
      }
      if(!visited[i][j]) {
        return false;
      }
    }
  }
  return true;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<pair<char, int>> answer;
  for(int i=1; i<=n; ++i) {
    if(ok(i, m, LEFT)) {
      answer.emplace_back('E', i);
    }
    if(ok(i, 1, RIGHT)) {
      answer.emplace_back('W', i);
    }
  }
  for(int j=1; j<=m; ++j) {
    if(ok(n, j, UP)) {
      answer.emplace_back('S', j);
    }
    if(ok(1, j, DOWN)) {
      answer.emplace_back('N', j);
    }
  }
  cout << answer.size() << "\n";
  for(auto p: answer) {
    cout << (char) (p.first) << p.second << " ";
  }
  cout << "\n";
  return 0;
}