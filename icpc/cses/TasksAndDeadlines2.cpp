#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + n + 1, [&](pair<int, int> a, pair<int, int> b) {
		if(a.second != b.second) {
			return a.second < b.second;
		}
		return a.first < b.first;
	});

	return 0;
}
