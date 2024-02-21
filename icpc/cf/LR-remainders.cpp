#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
stack<int> st;

inline void solve() {
	cin >> n >> m;
	vector<int> a(n), res;
	for(auto &x: a) {
		cin >> x;
	}
	cin >> s;
	int l = 0, r = n - 1;
	for(auto x: s) {
		if(x == 'L') {
			st.emplace(a[l++]);
		}
		else {
			st.emplace(a[r--]);
		}
	}
	int pref_mul = 1;
	while(!st.empty()) {
		pref_mul = (pref_mul * st.top()) % m;
		st.pop();
		res.emplace_back(pref_mul);
	}
	reverse(res.begin(), res.end());
	for(auto x: res) {
		cout << x << " ";
	}
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
