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
	vector<int> a(n + 1);
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		st.insert(i);
	}
	for(int i=1, x; i<=n; ++i) {
		cin >> x;
		auto it = st.find_by_order(x - 1);
		cout << a[*it] << "\n";
		st.erase(it);
	}
	return 0;
}
