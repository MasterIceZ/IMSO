#include <bits/stdc++.h>

using namespace std;

inline int ask(int a, int b) {
	cout << "? " << a << " " << b << endl;
	int x;
	cin >> x;
	if(x == a * b) {
		return 0;
	}
	if(x == a * (b + 1)) {
		return -1;
	}
	return 1;
}

inline void solve() {
	int l = 2, r = 999;
	while(l < r) {
		int seg_range = r - l + 1;
		int mid_l = l + (seg_range / 3);
		int mid_r = r - (seg_range / 3);
		int qry = ask(mid_l, mid_r);
		if(qry == 0) {
			l = mid_r + 1;
		}
		else if(qry == -1) {
			l = mid_l + 1;
			r = mid_r;
		}
		else {
			r = mid_l;
		}
	}
	cout << "! " << l << endl;
}

signed main(int argc, char *argv[]) {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
