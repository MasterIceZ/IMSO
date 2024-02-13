#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	ordered_set<int> st;
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		st.insert(i);
	}
	n /= 2;
	vector<int> a(n), b(n);
	for(auto &x: a) {
		cin >> x;
	}
	for(auto &x: b) {
		cin >> x;
	}
	vector<int> aa, bb;
	for(int i=0; i<n; ++i) {
		auto it = st.find_by_order(a[i] - 1);
		aa.emplace_back(*it);
		st.erase(it);
		it = st.find_by_order(b[i] - 1);
		bb.emplace_back(*it);
		st.erase(it);
	}
	for(auto x: aa) {
		cout << x << " ";
	}
	cout << "\n";
	for(auto x: bb) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}
