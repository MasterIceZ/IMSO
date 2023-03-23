#include <bits/stdc++.h>
using namespace std;

const int MxN = 100010;
int deg[MxN], cnt[3];
multiset<pair<int, int>> road;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q, u, v;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		cnt[0]++;
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		road.emplace(min(u, v), max(u, v));
		cnt[deg[u] & 1]--, cnt[deg[v] & 1]--;
		deg[u]++, deg[v]++;
		cnt[deg[u] & 1]++, cnt[deg[v] & 1]++;
	}
	for(int i=1, o; i<=q; ++i){
		cin >> o;
		if(o == 0){
			cin >> u >> v;
			road.emplace(min(u, v), max(u, v));
			cnt[deg[u] & 1]--, cnt[deg[v] & 1]--;
			deg[u]++, deg[v]++;
			cnt[deg[u] & 1]++, cnt[deg[v] & 1]++;
		}
		else if(o == 1){
			cin >> u >> v;
			if(!road.count(make_pair(min(u, v), max(u, v)))){
				continue;
			}
			road.erase(make_pair(min(u, v), max(u, v)));
			cnt[deg[u] & 1]--, cnt[deg[v] & 1]--;
			deg[u]--, deg[v]--;
			cnt[deg[u] & 1]++, cnt[deg[v] & 1]++;
		}
		else{
			cout << (cnt[1] == 0 ? "Y": "N") << "\n";	
		}
	}
	return 0;
}
