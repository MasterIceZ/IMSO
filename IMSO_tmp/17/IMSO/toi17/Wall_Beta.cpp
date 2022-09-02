/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Wall
 * ALGO		: Breadth First Search
 * DATE		: 29 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int n, m;
char a[1010][1010];
bool water[1010][1010];
queue<pair<int, int>> q;
int comp[1010][1010];

void bfs(int i, int j, int id){
	q.emplace(i, j);
	comp[i][j] = id;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(a[ii][jj] == '.' || comp[ii][jj]){
				continue;
			}
			q.emplace(ii, jj);
			comp[ii][jj] = id;
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	q.emplace(1, 1);
	water[1][1] = true;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(a[ii][jj] == 'X' || water[ii][jj]){
				continue;
			}
			water[ii][jj] = true;
			q.emplace(ii, jj);
		}
	}
	int it = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == 'X' && !comp[i][j]){
				bfs(i, j, ++it);
			}
		}
	}
	unordered_map<int, int> mp;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(water[i][j] || !comp[i][j]){
				continue;
			}
			for(int k=0; k<4; ++k){
				int ii = di[k] + i, jj = dj[k] + j;
				if(water[ii][jj] && comp[i][j]){
					mp[comp[i][j]] += 1;
				}
			}
		}
	}
	int ans = 0;
	for(auto x: mp){
		dbg(x.first, x.second);
		ans = max(ans, x.second);
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
