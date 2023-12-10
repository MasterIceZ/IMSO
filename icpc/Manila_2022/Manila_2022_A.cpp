#include <bits/stdc++.h>

using namespace std;

const int a = -2, b = 1, c = -14, d = 17;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int x;
  cin >> x;
  if(x <= -3) {
    cout << -(x + 4) * (x + 4) + 8;
  }
  else if(x <=2) {
    cout << a * x + b;
  }
  else {
    cout << x * x * x + c * x + d;
  }
  cout << "\n";
  return 0;
}