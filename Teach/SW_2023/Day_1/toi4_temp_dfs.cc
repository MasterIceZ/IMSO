#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 33;
int a[MxN][MxN];
bool visited[MxN][MxN];
int n, st_x, st_y, maxx = -1e9 - 100;

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

void dfs(int i, int j){
	visited[i][j] = true;
	maxx = max(maxx, a[i][j]);
	for(int k=0; k<4; ++k){
		int ii = di[k] + i, jj = dj[k] + j;
		if(ii < 1 || jj < 1 || ii > n || jj > n){
			continue;
		}
		if(visited[ii][jj] || a[ii][jj] == 100 || a[ii][jj] <= a[i][j]){
			continue;
		}
		dfs(ii, jj);
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> st_y >> st_x;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	dfs(st_x, st_y);
	cout << maxx << "\n";
	return 0;
}
// icy
