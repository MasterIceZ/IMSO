#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct State{
	int v;
	ll w;
	int state;
	bool operator < (const State& o) const {
		return w > o.w;
	}
	State(int _v, ll _w, int _state):
		v(_v), w(_w), state(_state) {}
};

const int MxN = 50050;
const int MxK = 22;

vector<pair<int, ll>> adj[MxN];
ll dist[MxK][MxN], w;
bitset<MxN> special;
priority_queue<State> pq;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, p, k, u, v, stp;
	cin >> n >> m >> p >> k;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=1, x; i<=p; ++i){
		cin >> x;
		special[x] = true;
	}
	cin >> stp;
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(stp, dist[0][stp] = 0, 0);
	while(!pq.empty()){
		State now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			ll nxt = now.w + x.second;
			if(special[x.first] && 1 + now.state <= k && dist[1 + now.state][x.first] > nxt){
				pq.emplace(x.first, dist[1 + now.state][x.first] = nxt, 1 + now.state);
			}
			if(dist[now.state][x.first] > nxt){
				pq.emplace(x.first, dist[now.state][x.first] = nxt, now.state);
			}
		}
	}
	ll res = dist[k][stp];
	cout << (res >= 1e18 + 100 ? "NO FOOD :(": to_string(res)) << "\n";
	return 0;
}
