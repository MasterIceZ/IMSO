#include <bits/stdc++.h>

using namespace std;

const int HASH_SIZE = 5e6 + 11;
const int MxN = 1550;

int a[5][MxN], b[5][MxN];

int real_value[HASH_SIZE]; // value of table[key]
pair<int, int> hashed_value[HASH_SIZE]; // value of key

inline int hash_function(pair<int, int> key) {
  return (HASH_SIZE + (((key.first + (key.second * 3)) % HASH_SIZE))) % HASH_SIZE;
}

void add_key(pair<int, int> key, pair<int, int> value) {
	int hash_key = hash_function(key);
  while(real_value[hash_key] != 0) {
    hash_key = (hash_key + 1) % HASH_SIZE;
  }
  real_value[hash_key] = (value.first * 1500) + value.second + 1;
  hashed_value[hash_key] = key;
}

pair<int, int> find_key(pair<int, int> key) {
	int hash_key = hash_function(key);
  while(real_value[hash_key] != 0) {
    if(hashed_value[hash_key] == key) {
      return make_pair((real_value[hash_key] - 1) / 1500, (real_value[hash_key] - 1) % 1500);
    }
    hash_key = (hash_key + 1) % HASH_SIZE;
  }
  return make_pair(-1, -1); // not found!
}

int main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int xt, yt, n;
  cin >> xt >> yt >> n;
  for(int state=1; state<=4; ++state) {
    for(int i=0; i<n; ++i) {
      cin >> a[state][i] >> b[state][i];
    }
  }
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      int sum_x = a[1][i] + a[2][j];
      int sum_y = b[1][i] + b[2][j];
      // mp[{sum_x, sum_y}] = {i, j};
      add_key(make_pair(sum_x, sum_y), make_pair(i, j));
    }
  }
  // cerr << "ADDED\n";
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      int remain_x = xt - a[3][i] - a[4][j];
      int remain_y = yt - b[3][i] - b[4][j];
      // mp[{remain_x, remain_y}] = ?
      pair<int, int> find_value = find_key(make_pair(remain_x, remain_y));
      if (find_value != make_pair(-1, -1)) {
        cout << a[1][find_value.first] << " " << b[1][find_value.first] << "\n";
        cout << a[2][find_value.second] << " " << b[2][find_value.second] << "\n";
        cout << a[3][i] << " " << b[3][i] << "\n";
        cout << a[4][j] << " " << b[4][j] << "\n";
        return 0;
      }
    }
  }
	return 0;
}