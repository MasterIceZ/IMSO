#include <bits/stdc++.h>
using namespace std ;

const int MxN = 33;
int n, m, t, dist[MxN][MxN];
char a[MxN][MxN];
pair<int, int> stp, edp;
queue<pair<int, int>> q;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

inline void solve(){
	cin >> n >> m >> t;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	cin >> stp.first >> stp.second >> edp.first >> edp.second;
	int cnt = 0;
	memset(dist, -1, sizeof dist);
	q.emplace(stp);
	dist[stp.first][stp.second] = 0;
	while(!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(a[ii][jj] == '#' || dist[ii][jj] != -1){
				continue;
			}
			q.emplace(ii, jj);
			dist[ii][jj] = dist[now.first][now.second] + 1;
			cnt++;
		}
	}
//	for(int i=1; i<=n; ++i){
//		for(int j=1; j<=m; ++j){
//			cout << dist[i][j] << " " ;
//		}
//		cout << "\n";
//	}
	if(dist[edp.first][edp.second] > t || dist[edp.first][edp.second] == -1){
		cout << -1;
		return ;
	}
	cout << 1 + min((t - dist[edp.first][edp.second]) / 2 + dist[edp.first][edp.second], cnt);
	return ;
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
