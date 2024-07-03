#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> sq;

inline void solve() {
	ll n;
	cin >> n;
	if(n == 12ll) {
		cout << "YES\n";
		return ;
	}
	if(n < 12ll) {
		cout << "NO\n";
		return ;
	}
	n -= 4;
	int idx_1 = upper_bound(sq.begin(), sq.end(), n) - sq.begin();
	idx_1--;
	for(int i=0; i<idx_1; ++i) {
		ll remains = n - sq[i];
		bool found = binary_search(sq.begin(), sq.end(), remains);
		if(found) {
			cerr << "D: " << remains << "\n";
			cout << "YES\n";
			return ;
		}
	}	
	cout << "NO\n";
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	bitset<100000> done;
	for(int i=3; i*i<=100000ll; i+=2) {
		if(done[i]) {
			continue;	
		}
		for(int j=i*i; j<=100000; j+=i) {
			done[j] = true;
		}
	}
	for(ll i=3; i<=100000ll; i+=2) {
		if(!done[i]) {
			sq.emplace_back(i * i);
		}
	}

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
