#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 2020;
char a[MxN][MxN];
queue<pair<int, int>> q;

const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			scanf(" %c", &a[i][j]);
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '0'){
				continue;
			}
			q.emplace(i, j);
			a[i][j] = '0';
			while(!q.empty()){
				pair<int, int> now = q.front(); q.pop();
				for(int k=0; k<8; ++k){
					int next_i = now.first + di[k];
					int next_j = now.second + dj[k];
					if(next_i < 1 || next_j < 1 || next_i > n || next_j > m){
						continue;
					}
					if(a[next_i][next_j] == '0'){
						continue;
					}
					q.emplace(next_i, next_j);
					a[next_i][next_j] = '0';
				}
			}
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}
// icy
