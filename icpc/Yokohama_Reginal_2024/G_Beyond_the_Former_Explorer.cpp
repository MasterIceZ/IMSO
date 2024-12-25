#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 5050;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};
const char chrs[] = {'^', '<', '>', 'v'};
const int UP = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int DOWN = 3;

int n, bound_up, bound_down, bound_left, bound_right;
pair<int, int> pos;
char a[MxN][MxN];

void ask(int x) {
  cout << chrs[x] << endl;
  pos.first += di[x];
  pos.second += dj[x];
  // cerr << "D: " << pos.first << " " << pos.second << endl;
  char t;
  cin >> t;
  if(t == 'G') {
    exit(0);
  }
  a[pos.first][pos.second] = t;
}

void walk(pair<int, int> ul, pair<int, int> dr) {
  // move to bound
  while(pos.first > dr.first) {
    ask(UP);
  }
  while(pos.second > dr.second) {
    ask(LEFT);
  }
  while(pos.second < ul.second) {
    ask(RIGHT);
  }
  while(pos.first < ul.first) {
    ask(DOWN);
  }
  
  int num_moves = (dr.first - ul.first) * 2 + (dr.second - ul.second) * 2 - 1;
  for(int i=1; i<=num_moves; ++i) {
    if(pos.second == dr.second && pos.first > ul.first) {
      ask(UP);
    }
    else if(pos.first == ul.first && pos.second > ul.second) {
      ask(LEFT);
    }
    else if(pos.first == dr.first && pos.second < dr.second) {
      ask(RIGHT);
    }
    else if(pos.second == ul.second && pos.first < dr.first) {
      ask(DOWN);
    }
  }
}

int go_in_count(pair<int, int> ul, pair<int, int> dr) {
  int cnt = 0;
  for(int i=ul.first; i<=dr.first; ++i) {
    if(ul.second - 1 >= 1 && a[i][ul.second - 1] == 'v') {
      cnt += 1;
    }
    if(a[i][ul.second] == '^') {
      cnt -= 1;
    }
    if(dr.second + 1 <= 2 * n + 1 && a[i][dr.second + 1] == '^') {
      cnt += 1;
    }
    if(a[i][dr.second] == 'v') {
      cnt -= 1;
    }
  }
  for(int j=ul.second; j<=dr.second; ++j) {
    if(ul.first - 1 >= 1 && a[ul.first - 1][j] == '>') {
      cnt += 1;
    }
    if(a[ul.first][j] == '<') {
      cnt -= 1;
    }
    if(dr.first + 1 <= 2 * n + 1 && a[dr.first + 1][j] == '<') {
      cnt += 1;
    }
    if(a[dr.first][j] == '>') {
      cnt -= 1;
    }
  }
  return cnt;
}

signed main(int argc, char *argv[]) {
  cin >> n;

  pos = make_pair(n + 1, n + 1);
  int middle_pos = n + 1;
  a[middle_pos][middle_pos] = '^';
  bound_up = bound_left = 1;
  bound_right = bound_down = 2 * n + 1;

  while(true) {
    int mid_updown = (bound_up + bound_down) / 2;
    walk(make_pair(mid_updown, bound_left), make_pair(mid_updown + 1, bound_right));
    if(go_in_count(make_pair(bound_up, bound_left), make_pair(mid_updown, bound_right)) == 0) {
      if(bound_up <= middle_pos && middle_pos <= mid_updown && bound_left <= middle_pos && middle_pos <= bound_right) {
        bound_down = mid_updown;
      }
      else {
        bound_up = mid_updown + 1;
      }
    }
    else {
      if(bound_up <= middle_pos && middle_pos <= mid_updown && bound_left <= middle_pos && middle_pos <= bound_right) {
        bound_up = mid_updown + 1;
      }
      else {
        bound_down = mid_updown;
      }
    }
    int mid_leftright = (bound_left + bound_right) / 2;
    walk(make_pair(bound_up, mid_leftright), make_pair(bound_down, mid_leftright + 1));
    if(go_in_count(make_pair(bound_up, bound_left), make_pair(bound_down, mid_leftright)) == 0) {
      if(bound_up <= middle_pos && middle_pos <= bound_down && bound_left <= middle_pos && middle_pos <= mid_leftright) {
        bound_right = mid_leftright;
      }
      else {
        bound_left = mid_leftright + 1;
      }
    }
    else {
      if(bound_up <= middle_pos && middle_pos <= bound_down && bound_left <= middle_pos && middle_pos <= mid_leftright) {
        bound_left = mid_leftright + 1;
      }
      else {
        bound_right = mid_leftright;
      }
    }
  }
  return 0;
}