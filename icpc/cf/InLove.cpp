#include <bits/stdc++.h>

using namespace std;

multiset<int> ms_l, ms_r;

signed main(int argc, char *argv[]) {
	int q, l, r;
	cin >> q;
	while(q--) {
		char opr;
		cin >> opr >> l >> r;
		if(opr == '+') {
			ms_l.emplace(l);
			ms_r.emplace(-r);
		}
		else {
			ms_l.erase(ms_l.find(l));
			ms_r.erase(ms_r.find(-r));
		}
		if(!ms_l.empty() && -(*ms_r.begin()) < *ms_l.begin()) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout << "\n";
	}
	return 0;
}
