#include <bits/stdc++.h>
using namespace std;

const int MxN = 1010;
vector<int> adj[MxN];
int orz[MxN], it = 0;

void PeaTTzaHuTT(int u, int p){
	orz[u] = it;
	for(auto x: adj[u]){
		if(x == p || orz[x] == it){
			continue;
		}
		PeaTTzaHuTT(x, u);
	}
}

int main(){
	int n, m, q, u, v;
	cin >> n >> m >> q;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
	}
	while(q--){
		it++;
		cin >> u >> v;
		PeaTTzaHuTT(u, 0);
		cout << (orz[v] == it ? "Yes" : "No") << "\n";
	}
	return 0;
}
