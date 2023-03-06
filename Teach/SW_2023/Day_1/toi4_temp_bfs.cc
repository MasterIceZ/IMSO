#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 1010;
int a[MxN][MxN];
queue<pair<int, int>> q;
bool visited[MxN][MxN];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};


int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, st_y, st_x;
	cin >> n >> st_y >> st_x;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	q.emplace(st_x, st_y);
	visited[st_x][st_y] = true;
	int maxx = -1e9 - 100;
	while(!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		maxx = max(maxx, a[now.first][now.second]);
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > n){
				continue;
			}
			if(visited[ii][jj] || a[ii][jj] == 100 || a[ii][jj] <= a[now.first][now.second]){
				continue;
			}
			q.emplace(ii, jj);
			visited[ii][jj] = true;
		}
	}
	cout << maxx << "\n";
	return 0;
}
// icy
