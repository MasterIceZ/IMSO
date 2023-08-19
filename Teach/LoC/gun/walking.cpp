#include <bits/stdc++.h>

using namespace std;

struct state_t {
	int i, j, w;
	bool operator < (const state_t& o) const {
		return w > o.w;
	}
	state_t(int _i, int _j, int _w):
		i(_i), j(_j), w(_w) {}
};

const int MxN = 1010;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

priority_queue<state_t> pq;
int n, dist[MxN][MxN];
char a[MxN][MxN], c[257];
string s;
pair<int, int> stp, edp;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	c['.'] = 1;
	c['*'] = 2;
	c['#'] = 3;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> s;
		s = " " + s;
		for(int j=1; j<=n; ++j) {
			a[i][j] = s[j];
		}
	}
	cin >> stp.first >> stp.second >> edp.first >> edp.second;
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(stp.first, stp.second, dist[stp.first][stp.second] = 0);
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		for(int k=0; k<4; ++k) {
			int ii = di[k] + now.i;
			int jj = dj[k] + now.j;
			if(ii < 1 || jj < 1 || ii > n || jj > n) {
				continue;
			}
			int nxt = now.w + c[(int) a[now.i][now.j]];
			if(dist[ii][jj] > nxt) {
				pq.emplace(ii, jj, dist[ii][jj] = nxt);
			}
		}
	}
	cout << dist[edp.first][edp.second] << "\n";
	return 0;
}
