#include <bits/stdc++.h>
using namespace std;

const int MxN = 1010;
vector<int> adj[MxN];
int dist[MxN], from_start[MxN];
queue<int> q;
queue<pair<int, int>> qq;

void solve(){
	int n, m, s, k, u, v;
	cin >> n >> m >> k >> s;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
	}
	for(int i=1; i<=n; ++i){
		from_start[i] = n + 1;
	}
	from_start[s] = 0;
	q.emplace(s);
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(auto x: adj[now]){
			if(from_start[x] > from_start[now] + 1){
				q.emplace(x);
				from_start[x] = from_start[now] + 1;
			}
		}
	}
	int ans = 1e9 + 100, ans_2 = -1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			dist[j] = n + 1;
		}
		qq.emplace(i, 0);
		while(!qq.empty()){
			pair<int, int> now = qq.front(); qq.pop();
			for(auto x: adj[now.first]){
				int nxt = now.second + 1;
				if(dist[x] > nxt){
					qq.emplace(x, nxt);
					dist[x] = nxt;
				}
			}
		}
		if(dist[i] > n || from_start[i] > n){
			continue;
		}
		int d = from_start[i];
		if(i == s){
			d = 0;
		}	
		int r = d + (k - 1) * dist[i];
		if(r < ans){
			ans = r;
			ans_2 = i;
		}
	}
	if(ans_2 == -1){
		cout << "-1";
	}
	else{
		cout << ans << " " << ans_2;
	}
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
}
