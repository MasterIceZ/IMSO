#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

pair<int, int> a[MxN];
multiset<int> ms;
vector<int> mem;

signed main(int argc, char *argv[]) {
	int n, m, h, q;
	scanf("%d %d %d %d", &n, &m, &h, &q);
	for(int i=1; i<=n; ++i) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	for(int i=1, x; i<=m; ++i) {
		scanf("%d", &x);
		ms.emplace(x);
	}
	for(int i=1; i<=n; ++i) {
		auto it = ms.lower_bound(abs(a[i].second - h));
		if(it == ms.end()) {
			continue;
		}
		ms.erase(it);
		mem.emplace_back(a[i].first);
	}
	for(int x; q--; ) {
		cin >> x;
		x -= 1;
		printf("%d\n", x < mem.size() ? mem[x]: -1);
	}
}
