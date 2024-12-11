#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int c[2][2];

inline void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	if(s == t) {
		cout << "YES\n";
		return ;
	}
	c[0][0] = c[0][1] = c[1][0] = c[1][1] = 0;
	for(auto v: s) {
		c[0][v - '0'] = !c[0][v - '0'];
	}
	for(auto v: t) {
		c[1][v - '0'] = !c[1][v - '0'];
	}
	if(c[0][0] != c[1][1] || c[0][1] != c[1][0]) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
	cout << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
