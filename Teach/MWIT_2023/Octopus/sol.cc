#include <bits/stdc++.h>
using namespace std;

const int MxN = 100010;
int in_circle = 0, cir[MxN], dist[MxN], parent[MxN];

inline int get_dist(int u, int v){
	return abs(dist[u] - dist[v]);
}

inline int get_circle_dist(int u, int v){
	if(u > v){
		swap(u, v);
	}
	int u_v = cir[v - 1] - cir[u - 1];
	//cerr << "D : " << u << " -> " << v << ": " << u_v << "\n";
	return min(u_v, in_circle - u_v);
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, k, u, v, w;
	cin >> n >> k;
	for(int i=1; i<=k; ++i){
		cin >> w; // (i, i + 1)
		if(i != k){
			cir[i] = cir[i - 1] + w;
		}
		in_circle = in_circle + w;
		parent[i] = i;
	}
	for(int i=k+1; i<=n; ++i){
		cin >> v >> w;
		parent[i] = parent[v];
		dist[i] = dist[v] + w;
	}
	int q;
	cin >> q;
	while(q--){
		cin >> u >> v;
		if(parent[u] == parent[v]){
			cout << get_dist(u, v);
		}
		else{
			cout << get_dist(u, parent[u]) + get_dist(v, parent[v]) + get_circle_dist(parent[u], parent[v]);
		}
		cout << "\n";
	}
	return 0;
}
