#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

int idx[MxN << 1];
bool is_greater[MxN << 1][MxN << 1];
vector<int> p[MxN << 1];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		idx[i] = i;
	}

	auto build = [&](int a, int b) {
		int min_sz = min((int) p[a].size(), (int) p[b].size());
		for(int i=0; i<min_sz; ++i) {
			int x = p[a][i], y = p[b][i];
			if(is_greater[x][y]) {
				return true;
			}
			if(is_greater[y][x]) {
				return false;
			}
		}	
		return p[a].size() > p[b].size();
	};

	while(q--) {
		char opr;
		int x, y;
		cin >> opr >> x >> y;
		if(opr == '?') {
			x = idx[x];
			y = idx[y];
			if(is_greater[x][y]) {
				cout << ">";
			}
			else if(is_greater[y][x]) {
				cout << "<";
			}
			else {
				cout << "=";
			}
			cout << "\n";
		}
		else {
			n++;
			p[n] = p[idx[x]];
			p[n].emplace_back(idx[y]);
			idx[x] = n;
			sort(p[n].begin(), p[n].end(), [&](int a, int b) {
				return is_greater[a][b];
			});
			for(int i=1; i<=n; ++i) {
				is_greater[i][n] = build(i, n);
				is_greater[n][i] = build(n, i);
			}
		}
	}
	return 0;
}
