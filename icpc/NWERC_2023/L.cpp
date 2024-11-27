#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

queue<pair<int, int>> q;
bool done[MxN][MxN];

signed main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if((i + j) % 5 != 2) {
				continue;
			}
			q.emplace(i, j);
			done[i][j] = true;
		}
	}
	int remain_ships = 5 * k;

	auto ask = [&](pair<int, int> p) {
		string s;
		cout << p.first << " " << p.second << endl;
		cin >> s;
		return s != "miss";
	};

	while(!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		if(!ask(now)) {
			continue;
		}
		if(--remain_ships == 0) {
			break;
		}
		for(int k=0; k<4; ++k) {
			int ii = now.first + di[k];
			int jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > n) {
				continue;
			}	
			if(done[ii][jj]) {
				continue;
			}
			done[ii][jj] = true;
			q.emplace(ii, jj);
		}
	}
	return 0;
}
