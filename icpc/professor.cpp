// Hydrolyzed~
#include <bits/stdc++.h>

using namespace std;

const int MxN = 2020;
const int MxA = 550;

bitset<MxN * MxA> bs;

signed main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, sum = 0;
	cin >> n;
	bs[0] = true;
	for(int i=1, x; i<=n; ++i) {
		cin >> x;
		bs |= bs << x;
	 	sum += x;
	}
	if(sum % 2 == 0 && bs[sum / 2]) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	cout << "\n";
	return 0;
}
