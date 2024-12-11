#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int c[2][2];

inline void solve() {
	int n, k, p;
	cin >> n >> k >> p;
	vector<int> v(n);
	for(auto &x: v) {
		cin >> x;
	}
	int a = *max_element(v.begin(), v.end());
	int b = accumulate(v.begin(), v.end(), 0) - a;
	if(a + k > b + p) {
		cout << "Ved";
	}
	else if(a + k < b + p) {
		cout << "Varun";
	}
	else {
		cout << "Equal";
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
