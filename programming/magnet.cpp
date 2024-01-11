#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> mp;
vector<int> line;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1, a, k; i<=m; ++i) {
		cin >> a >> k;
		mp[a]++, mp[a + k]--;
	}
	for(auto x: mp) {
		if(x.second % 2 == 0) {
			continue;
		}
		line.emplace_back(x.first);
	}
	while(q--) {
		int x;
		cin >> x;
		if(x < line[0]) {
			cout << line[0] - 1;
		} else if(x >= line.back()) {
			cout << n - line.back() + 1;
		} else {
			auto it = upper_bound(line.begin(), line.end(), x);
			cout << (*it - *(--it));
		}
		cout << "\n";
	}
	return 0;
}
