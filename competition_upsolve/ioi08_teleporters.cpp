#include <bits/stdc++.h>

using namespace std;

const int MxP = 2000020;

int nxt[MxP];
bool visited[MxP];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<MxP-1; ++i) {
		nxt[i] = i + 1;
	}
	visited[MxP-1] = true;
	for(int i=1, l, r; i<=n; ++i) {
		cin >> l >> r;
		nxt[l - 1] = r;
		nxt[r - 1] = l;
	}
	vector<int> v;
	for(int i=0; i<MxP; ++i) {
		if(visited[i]) {
			continue;
		}
#ifdef ICY
		cerr << "X: " << i << "\n";
#endif
		int cur = i, cnt_warp = 0;
		while(!visited[cur]) {
			visited[cur] = true;
			if(nxt[cur] != cur + 1) {
#ifdef ICY
				cerr << "FROM (" << cur << ") to (" << nxt[cur] << ")\n";
#endif
				cnt_warp++;
			}
			cur = nxt[cur];
		}
#ifdef ICY
		cerr << "WRP: " << cnt_warp << "\n";
#endif
		v.emplace_back(cnt_warp);
	}
#ifdef ICY
	cerr << "D: " << v[0] << "\n";
#endif
	int answer = v[0];
	v.erase(v.begin());
	sort(v.begin(), v.end(), greater<int> ());
	for(int i=0; i<m && i<(int) v.size(); ++i) {
#ifdef ICY
		cerr << "USING: " << v[i] << "\n";
#endif
		answer += 2 + v[i];
	}
	int remain = m - v.size();
	if(remain > 0) {
		answer += (remain + 1) / 2 + (remain / 2) * 3;
	}
	cout << answer << "\n";
	return 0;
}
