#include <bits/stdc++.h>

using namespace std;
using ll = long long;

stack<ll> st, st2;
string s;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--) {
		int n;
		ll m, x;
		deque<ll> v;
		cin >> n >> m;
		for(int i=0; i<n; ++i) {
			cin >> x;
			v.emplace_back(x);
		}
		cin >> s;
		for(int i=0; i<n; ++i) {
			if(s[i] == 'L') {
				st.emplace(v.front());
				v.pop_front();
			}
			else {
				st.emplace(v.back());
				v.pop_back();
			}
		}
		ll answer = 1ll % m;
		while(!st.empty()) {
			ll cur = st.top(); st.pop();
			answer = (answer * cur) % m;
			st2.emplace(answer);
		}
		while(!st2.empty()) {
			cout << st2.top() << " ";
			st2.pop();
		}
		cout << "\n";
	}
	return 0;
}
