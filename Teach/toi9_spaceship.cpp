#include <bits/stdc++.h>

using namespace std;

const int MxN = 11;
const int INF = 1e9 + 100;

struct state_t {
	int mask, dist, last;
	state_t(int _mask, int _dist, int _last): 
		mask(_mask), dist(_dist), last(_last) {}
	bool operator < (const state_t &o) const {
		return dist > o.dist;
	}
};

struct shop_t {
	int x, y, z, a, b, c;
};

shop_t shop[MxN], stp;
int m, dist[1 << MxN][MxN];
priority_queue<state_t> pq;

inline shop_t get_pos(int idx) {
	shop_t tmp;
	if(idx == 0) {
		tmp.x = stp.x;
		tmp.y = stp.y;
		tmp.z = stp.z;
	}
	else {
		tmp.x = shop[idx].x;
		tmp.y = shop[idx].y;
		tmp.z = shop[idx].z;
	}
	return tmp;
}

inline int p2(int x) {
	return x * x;
}

inline array<int, 3> get_count(int mask) {
	array<int, 3> cnt = {0, 0, 0};
	for(int i=0; i<m; ++i) {
		if(!(mask & (1 << i))) {
			continue;
		}
		cnt[0] += shop[i + 1].a;
		cnt[1] += shop[i + 1].b;
		cnt[2] += shop[i + 1].c;
	}
	return cnt;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(0);
	int n, answer = INF;
	cin >> n >> stp.x >> stp.y >> stp.z >> m;
	for(int i=1; i<=m; ++i) {
		cin >> shop[i].x >> shop[i].y >> shop[i].z >> shop[i].a >> shop[i].b >> shop[i].c;
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(0, dist[0][0] = 0, 0);
	while(!pq.empty()) {
		state_t cur = pq.top();
		pq.pop();
		if(cur.dist > dist[cur.mask][cur.last]) {
			continue;
		}
		array<int, 3> cur_count = get_count(cur.mask);
		if(cur_count[0] >= n && cur_count[1] >= n && cur_count[2] >= n) {
			answer = min(answer, cur.dist);
			continue;
		}
		shop_t cur_pos = get_pos(cur.last);
		for(int i=1; i<=m; ++i) {
			if(cur.mask & (1 << (i - 1))) {
				continue;
			}
			int new_mask = cur.mask | (1 << (i - 1));
			int new_dist = cur.dist + p2(cur_pos.x - shop[i].x) + p2(cur_pos.y - shop[i].y) + p2(cur_pos.z - shop[i].z);
			if(dist[new_mask][i] > new_dist) {
				pq.emplace(new_mask, dist[new_mask][i] = new_dist, i);
			}
		}
	}
	cout << answer << "\n";
	return 0;
}
