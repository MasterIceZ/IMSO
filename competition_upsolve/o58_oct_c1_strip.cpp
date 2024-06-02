#include <bits/stdc++.h>

using namespace std;

const int MxW = 100010;

template<typename T>
struct fenwick_tree {
	T *t;
	int n;

	fenwick_tree(int _n): n(_n) {
		t = (T *) calloc(n + 1, sizeof(T));
	}

	void update(int idx, T v) {
		for(; idx<=n; idx+=idx&-idx) {
			t[idx] += v;
		}
	}

	T query(int idx) {
		T res = 0;
		for(; idx>0; idx-=idx&-idx) {
			res += t[idx];
		}
		return res;
	}
};

vector<pair<int, int>> evp[MxW], query[MxW];
int answer[MxW];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1, a, b, c, d; i<=n; ++i) {
		cin >> a >> b >> c >> d;
		a++, b++, c++, d++;
		evp[a].emplace_back(b, 1);
		evp[a].emplace_back(d + 1, -1);
		evp[c + 1].emplace_back(b, -1);
		evp[c + 1].emplace_back(d + 1, 1);
	}	
	
	for(int i=1, x, y; i<=m; ++i) {
		cin >> x >> y;
		x++, y++;
		query[x].emplace_back(y, i);
	}

	fenwick_tree<int> fw(MxW);
	for(int i=1; i<MxW; ++i) {
		for(auto x: evp[i]) {
			fw.update(x.first, x.second);
		}
		for(auto x: query[i]) {
			answer[x.second] = fw.query(x.first);
		}
	}
	
	for(int i=1; i<=m; ++i) {
		cout << answer[i] << "\n";
	}

	return 0;
}
