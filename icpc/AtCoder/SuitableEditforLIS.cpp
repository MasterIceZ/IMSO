#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

struct max_fenwick {
	int tree[MxN << 1];
	void update(int idx, int v) {
		for(; idx <(MxN << 1); idx+=idx&-idx) {
			tree[idx] = max(tree[idx], v);
		}
	}
	int query(int idx) {
		int res = 0;
		for(; idx>0; idx-=idx&-idx) {
			res = max(res, tree[idx]);
		}
		return res;
	}
	void clear() {
		for(int i=1; i<(MxN << 1); ++i) {
			tree[i] = 0;
		}
	}
};

int a[MxN], from_front[2][MxN], from_back[2][MxN];
vector<int> c;
max_fenwick fw;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		c.emplace_back(a[i]);
		c.emplace_back(a[i] + 1);
	}

	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for(int i=1; i<=n; ++i) {
		a[i] = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
	}

	for(int i=1; i<=n; ++i) {
		from_front[0][i] = fw.query(a[i] - 1) + 1;
		fw.update(a[i], from_front[0][i]);
		from_front[1][i] = a[i];
	}
	for(int i=1; i<=n; ++i) {
		a[i] = (MxN << 1) - (a[i] + 1);
	}
	fw.clear();
	for(int i=n; i>=1; --i) {
		from_back[0][i] = fw.query(a[i] - 1) + 1;	
		fw.update(a[i], from_back[0][i]);
		from_back[1][i] = from_front[1][i];
	}

	from_front[1][0] = -1e9 - 100;
	for(int i=1; i<=n; ++i) {
		if(from_front[0][i] < from_front[0][i - 1]) {
			from_front[0][i] = from_front[0][i - 1];
			from_front[1][i] = from_front[1][i - 1];
		}
		else if(from_front[0][i] == from_front[0][i - 1]) {
			from_front[1][i] = min(from_front[1][i], from_front[1][i - 1]);
		}
	}
	
	from_back[1][n + 1] = 1e9 + 100;
	for(int i=n; i>=1; --i) {
		if(from_back[0][i] < from_back[0][i + 1]) {
			from_back[0][i] = from_back[0][i + 1];
			from_back[1][i] = from_back[1][i + 1];
		}
		else if(from_back[0][i] == from_back[0][i + 1]) {
			from_back[1][i] = max(from_back[1][i], from_back[1][i + 1]);
		}
	}

	int answer = from_front[0][n];
	for(int i=1; i<=n; ++i) {
		if(from_front[1][i - 1] + 1 < from_back[1][i + 1]) {
			answer = max(answer, from_front[0][i - 1] + 1 + from_back[0][i + 1]);
		}
	}

	cout << answer << "\n";

	return 0;
}
