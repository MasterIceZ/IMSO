#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u, v, idx;
	bool operator < (const Edge& o) const {
		if(u != o.u){
			return u < o.u;
		}
		if(v != o.v){
			return v < o.v;
		}
		return idx < o.idx;
	}
	Edge(int _u, int _v, int _idx):
		u(_u), v(_v), idx(_idx) {}
};

using ll = long long;
const int MxN = 100010;
vector<pair<int, ll>> adj[MxN];
vector<pair<ll, int>> query;
vector<ll> ww;
vector<Edge> special;
int lv[MxN], lift[22][MxN];
ll mwei[22][MxN], answer[MxN];

void dfs(int u, int p, ll w){
	lv[u] = lv[p] + 1;
	lift[0][u] = p;
	mwei[0][u] = w;
	for(auto x: adj[u]){
		if(x.first == p || lv[x.first]){
			continue;
		}
		dfs(x.first, u, x.second);
	}
}

ll get_max(int u, int v){
	if(lv[u] > lv[v]){
		swap(u, v);
	}
//	cerr << "LCA : " << u << " " << v << "\n";
	ll maxx = 0ll;
	for(int state=20; state>=0; --state){
		if(lv[u] > lv[lift[state][v]]){
			continue;
		}
		maxx = max(maxx, mwei[state][v]);
		v = lift[state][v];
	}
	if(u == v){
		return maxx;
	}
	for(int state=20; state>=0; --state){
		if(lift[state][u] == lift[state][v]){
			continue;
		}
		maxx = max({maxx, mwei[state][u], mwei[state][v]});
		u = lift[state][u];
		v = lift[state][v];
	}
	return max({maxx, mwei[0][u], mwei[0][v]});
}

int main(){
	int n, m, u, v;
	ll w;
	cin >> n >> m;
	for(int i=1; i<n; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	dfs(1, 0, 0ll);
	for(int state=1; state<=20; ++state){
		for(int i=1; i<=n; ++i){
			lift[state][i] = lift[state - 1][lift[state - 1][i]];
			mwei[state][i] = max(mwei[state - 1][lift[state - 1][i]], mwei[state - 1][i]);
		}
	}
	int it = 0;
	for(int i=n; i<=m; ++i){
		cin >> u >> v >> w;
		special.emplace_back(u, v, i - n);
		ww.emplace_back(w);
	}
	for(auto x:special){
		query.emplace_back(get_max(x.u, x.v), x.idx);
//		cerr << "D : " << x.u << " " << x.v << " " << get_max(x.u, x.v) << "\n";
	}
	sort(ww.begin(), ww.end());
	sort(query.begin(), query.end());
	for(int i=0; i<query.size(); ++i){
		if(query[i].first >= ww[i]){
			cout << "0";
			return 0;
		}
		answer[query[i].second] = ww[i];
	}
	cout << "1\n";
	for(int i=0; i<=m-n; ++i){
		cout << answer[i] << "\n";
	}
	return 0;
}
