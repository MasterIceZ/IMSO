#include <bits/stdc++.h>
using namespace std;

const int MxN = 100010;
vector<int> adj[MxN], big_adj[MxN];
int value[MxN], mem[MxN];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, u, v, q;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	int sq = sqrt(n);
	cin >> q;
	while(q--){
		char opr;
		cin >> opr;
		if(opr == 'U'){
			int x, v;
			cin >> x >> v;
			if(adj[x].size() <= sq){
				for(auto a: adj[x]){
					value[a] += v;
				}
				value[x] += v;
			}
			else{
				mem[x] += v;
				big.emplace(x);
			}
		}
		else{
			int x;
			cin >> x;
			int sum = mem[x] + value[x];
			for(auto a: adj[x]){
				if(adj[a].size() > sq){
					sum += mem[a];
				}
			}
			cout << sum << "\n";
		}
	}
	return 0;
}
