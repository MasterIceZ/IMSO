// Hydrolyzed~
#include <bits/stdc++.h>

using namespace std;

vector<bool> getBit(int n) {
	vector<bool> b;
	while(n > 0) {
		b.emplace_back(n & 1);
		n >>= 1;
	}
	return b;
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, k, answer = 0;
	cin >> n >> k;
	for(int i=1; i<=n; ++i) {
		vector<bool> b = getBit(i);
		int cnt = 0;
		for(int j=1; j<(int) b.size(); ++j) {
			cnt += (b[j] != b[j - 1]);
		}
		if(cnt == k) {
			answer += 1;
		}
//		cerr << "debug (" << i << ") :";
//		for(int j=0; j<(int) b.size(); ++j) {
//			cerr << (b[j] ? "1": "0");
//		}
//		cerr << "\n";
	}
	cout << answer << "\n";
	return 0;
}
