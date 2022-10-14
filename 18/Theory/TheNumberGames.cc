#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6 + 10;
vector<int> adj[MxN];
int deg[MxN];

int main(){
	int n, k;
	cin >> n >> k;
	for(int i=2; i<=n; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		deg[u]++, deg[v]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=1; i<=n; ++i){
		if(deg[i] == 1){
			pq.emplace(i);
		}
	}
	vector<int> res;
	while(!pq.empty()){
		int now = pq.top(); pq.pop();
		res.emplace_back(now);
		if((int) res.size() == k){
			break;
		}
		for(auto x: adj[now]){
			if(--deg[x] == 1){
				pq.emplace(x);
			}
		}
	}
	sort(res.begin(), res.end());
	for(auto x: res){
		cout << x << " " ;
	}
	return 0;
}
