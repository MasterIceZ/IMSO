#include <bits/stdc++.h>
#include <ext/stdc++.h>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MxN = 2000020;
map<ll, int> mp;
ordered_set<pair<ll, int>> st;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n, t, a, b;
	ll x;
	cin >> n >> t;
	cin >> a >> b;
	for(int i=1; i<=n; ++i) {
		cin >> x;
		st.insert(make_pair(x, ++mp[x]));
	}
	auto gen = [&](ll x, ll y) {
		return make_pair(x - y, (x + y) / 2ll);
	};
	for(int i=1; i<=t; ++i) {
		auto it_a = st.find_by_order(a - 1);
		auto it_b = st.find_by_order(b - 1);	
		pair<ll, ll> g = gen(it_a->first, it_b->first);
		st.erase(it_a);
		st.erase(it_b);
		st.insert(g.first, ++mp[g.first]);
		st.insert(g.second, ++mp[g.second]);
	}
	for(auto x: st) {
		cout << x->first << "\n";
	}
	return 0;
}

