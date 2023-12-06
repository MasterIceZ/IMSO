#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while(q--) {
    string s;
    cin >> s;
    for(int i='a'; i<s[0]; ++i) {
      cout << ((char)(i)) << s[1] << "\n";
    }
    for(int i=s[0]+1; i<='h'; ++i) {
      cout << ((char)(i)) << s[1] << "\n";
    }
    for(int i='1'; i<s[1]; ++i) {
      cout << s[0] << ((char)(i)) << "\n";
    }
    for(int i=s[1]+1; i<='8'; ++i) {
      cout << s[0] << ((char)(i)) << "\n";
    }
  }
}