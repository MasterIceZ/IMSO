#include <bits/stdc++.h>
using namespace std;

struct State{
	int v, w;
	bool operator < (const State& o) const {
		return w > o.w;
	}
	State(int _v, int _w):
		v(_v), w(_w) {}
};

struct Answer{
	pair<int, int> edge;
	int it;
	bool operator < (const Answer& o) const {
		return it < o.it;
	}
	Answer(pair<int, int> _edge, int _it):
		edge(_edge), it(_it) {}
};

using pii = pair<int, int> ;
const int MxN = 20020;
vector<pii> adj[MxN];
vector<Answer> uses;
priority_queue<State> pq;
int parent[MxN], dist[MxN];
vector<int> g_s;
map<pii, int> used;
map<pii, pii> edges;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, k, p;
	cin >> n >> m >> k >> p;
	for(int i=1, x; i<=k; ++i){
		cin >> x;
		g_s.emplace_back(x);
	}
	for(int i=1; i<=m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		edges[{u, v}] = edges[{v, u}] = {u, v};
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(p, dist[p] = 0);
	while(!pq.empty()){
		State now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			int nxt = now.w + x.second;
			if(dist[x.first] > nxt){
				pq.emplace(x.first, dist[x.first] = nxt);
				parent[x.first] = now.v;
			}
		}
	}
	for(auto x: g_s){
		int it = 0, now = x;
		while(now != p){
			if(used[edges[{now, parent[now]}]] < it + 1){
				used[edges[{now, parent[now]}]] = ++it;
			}
			else{
				break;
			}
			now = parent[now];
		}
	}
	for(auto x: used){
		uses.emplace_back(x.first, x.second);
	}
	sort(uses.begin(), uses.end());
	for(auto x: g_s){
		cout << dist[x] << " ";
	}
	cout << "\n" << uses.size() << "\n";
	for(auto x: uses){
		cout << x.edge.first << " " << x.edge.second << "\n";
	}
	return 0;
}