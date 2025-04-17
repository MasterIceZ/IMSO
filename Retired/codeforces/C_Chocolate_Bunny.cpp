#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int ask(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int r;
  cin >> r;
  return r;
}

void answer(vector<int> v) {
  cout << "!";
  for(auto e: v) {
    cout << " " << e;
  }
  cout << endl;
}

signed main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> mem(n, -1);
  int maxx = 0;
  for(int i=1; i<n; ++i) {
    int x = ask(maxx + 1, i + 1), y = ask(i + 1, maxx + 1);
    if(x > y) {
      mem[maxx] = x;
      maxx = i;
    }
    else {
      mem[i] = y;
    }
  }
  mem[maxx] = n;
  answer(mem);
  return 0;
}