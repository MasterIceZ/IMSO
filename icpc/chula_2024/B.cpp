#include <bits/stdc++.h>

using namespace std;

const int MxN = 5000050;

int idx[MxN], a[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int m, n, k;
	cin >> m >> n >> k;
	for(int i=1; i<=m; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + m + 1);
	int s = m - n - 1;
	for(int i=1; i<=m; ++i) {
		idx[a[i]] = i;
	}
	for(int g=1; g<MxN; ++g) {
		vector<int> v;
		for(int gg=g; gg<MxN; gg+=g) {
			if(idx[i] != 0) {
				v.emplace_back(idx[i]);
			}

		}
	}
}
