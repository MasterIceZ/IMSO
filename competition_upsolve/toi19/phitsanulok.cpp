#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MxS = 1 << 19;

struct State{
	int v, w;
	bool operator < (const State& o) const {
		return w > o.w;
	}
	State(int _v, int _w):
		v(_v), w(_w) {}
};

priority_queue<State> pq;
vector<pair<int, int>> adj[MxS];
int dist[MxS], mem[MxS];

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, s, w, poi, ant, x;
	cin >> n >> s;
	for(int bit=0; bit<(1 << s); ++bit){
		for(int state=0; state<s; ++state){
			if(bit & (1 << state)){
				adj[bit].emplace_back(bit ^ (1 << state), 0);
			}
		}
		dist[bit] = 1e9 + 100;
	}
	for(int i=1; i<=n; ++i){
		cin >> w;
		ant = poi = 0;
		for(int state=0; state<s; ++state){
			cin >> x;
			if(x == -1){
				poi |= (1 << state);
			}
			else if(x == 1){
				ant |= (1 << state);
			}
		}
		mem[i] = poi;
		adj[poi].emplace_back(ant, w);
	}
	pq.emplace(0, dist[0] = 0);
	while(!pq.empty()){
		State now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			int nxt = now.w + x.second;
			if(dist[x.first] > nxt){
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
	int answer = 0;
	for(int i=1; i<=n; ++i){
		int state = mem[i];
		if(dist[state] >= 1e9 + 100){
			continue;
		}
		answer = max(answer, dist[state]);
	}
	cout << answer;
	return 0;
}
