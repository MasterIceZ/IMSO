#include <bits/stdc++.h>

using namespace std;

const int MxN = 22;
const int MxP = 10010;

int a[MxP][MxN], b[MxP];

signed main(int argc, char *argv[]) {
  int n, p;
  cin >> n >> p;
  for(int i=1; i<=p; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> a[i][j];
    }
    cin >> b[i];
  }
  cout << ".i " << n << "\n";
  cout << ".o " << 1 << "\n";
  cout << ".ilb";
  for(int i=0; i<n; ++i) {
    cout << " " << ((char) (i + 'A'));
  }
  cout << "\n";
  cout << ".ob Z\n";
  cout << ".p " << p << "\n";
  for(int i=1; i<=p; ++i) {
    for(int j=1; j<=n; ++j) {
      cout << a[i][j];
    }
    cout << " " << b[i] << "\n";
  }
  cout << ".e\n";
  return 0;
}