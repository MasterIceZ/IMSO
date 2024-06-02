#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template<typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MxN = 2000020;
ordered_multiset<int> ms;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int x, n, t, a, b;
	cin >> n >> t;
	cin >> a >> b;
	for(int i=1; i<=n; ++i) {
		cin >> x;
		ms.insert(x);
	}
	for(int i=1; i<=t; ++i) {
		auto it_a = ms.find_by_order(a - 1);
		auto it_b = ms.find_by_order(b - 1);	
		int val_a = *it_a, val_b = *it_b;
		ms.erase(it_a);
		ms.erase(it_b);
		ms.insert(val_b - val_a);
		ms.insert((val_a + val_b) / 2);
	}
	for(auto x: ms) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

