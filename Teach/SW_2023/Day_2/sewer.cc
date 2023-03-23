#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int MxN = 110;
vector<pii> adj[MxN][MxN];
int dist[MxN][MxN];
queue<pii> q;

int main(){
	int n, m;
	char x;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			scanf(" %c", &x);
			if(x == 'R' || x == 'B'){
				adj[i][j].emplace_back(i, j + 1);
				adj[i][j + 1].emplace_back(i, j);
			}
			if(x == 'D' || x == 'B'){
				adj[i][j].emplace_back(i + 1, j);
				adj[i + 1][j].emplace_back(i, j);
			}
		}
	}
	memset(dist, -1, sizeof dist);
	dist[1][1] = 1;
	q.emplace(1, 1);
	while(!q.empty()){
		pii now = q.front(); q.pop();
		for(auto next_position: adj[now.first][now.second]){
			int next_dist = dist[now.first][now.second] + 1;
			if(dist[next_position.first][next_position.second] != -1 && 
					next_dist > dist[next_position.first][next_position.second]){
				continue;
			}
			if(next_dist == dist[next_position.first][next_position.second]){
				printf("%d\n%d %d\n", next_dist, next_position.first, next_position.second);
				return 0;
			}
			dist[next_position.first][next_position.second] = next_dist;
			q.emplace(next_position);
		}
	}
	return 0;
}
