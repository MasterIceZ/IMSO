#include <bits/stdc++.h>

using namespace std;

const int MxR = 330;
const int MxC = 5050;

struct tile_t {
	int pos_x, pos_y, val, t;
	tile_t(int _pos_x, int _pos_y, int _val, int _t):
		pos_x(_pos_x), pos_y(_pos_y), val(_val), t(_t) {}
	bool operator < (const tile_t &o) const {
		return val > o.val;
	}
};

priority_queue<tile_t> pq;
pair<int, int> table[MxR][MxC];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int r, c, q, opr, x, y, v, it = 0;
	cin >> r >> c >> q;
	for(int i=1; i<=r; ++i) {
		for(int j=1; j<=c; ++j) {
			pq.emplace(i, j, 0, 0);
		}
	}
	while(q--) { 
		cin >> opr;
		if(opr == 1) {
			cin >> x >> y >> v;
			table[x][y] = make_pair(v, ++it);
			pq.emplace(x, y, v, it);
		}
		else if(opr == 2) {
			cin >> x >> v;
			table[x][0] = make_pair(v, ++it);
			pq.emplace(x, 0, v, it);
		}
		else if(opr == 3) {
			cin >> x >> y;
			if(table[x][0].second > table[x][y].second) {
				cout << table[x][0].first << "\n";
			}
			else {
				cout << table[x][y].first << "\n";
			}
		}
		else {
			while(!pq.empty()) {
				tile_t cur = pq.top();
				if(cur.pos_y != 0) {
					if(table[cur.pos_x][cur.pos_y].second > cur.t || table[cur.pos_x][0].second > cur.t) {
						pq.pop();
						continue;
					}
					cout << cur.val << "\n";
					break;
				}
				bool ok = false;
				if(table[cur.pos_x][0].second > cur.t) {
					pq.pop();
					continue;
				}
				for(int j=1; j<=c; ++j) {
					if(table[cur.pos_x][j].second < cur.t) {
						ok = true;
						break;
					}
				}
				if(!ok) {
					pq.pop();
					continue;
				}
				cout << cur.val << "\n";
				break;
			}
		}
	}
	return 0;
}
