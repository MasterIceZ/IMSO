#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct fraction {
  ll a, b; 
  fraction(ll _a, ll _b):
    a(_a), b(_b) {}
  fraction operator + (const ll x) {
    return fraction(x * b + a, b);
  }
};

fraction brute_force(int state) {
  if(state == 1) {
    return fraction(1, 2);
  }
  fraction t = brute_force(state - 1) + 1;
  return fraction(t.b, t.a);
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cout << brute_force(n).a << "\n";
  return 0;
}