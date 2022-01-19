#include <bits/stdc++.h>
#include "emergency.h"

using namespace std;

#ifdef _DEBUG
#include "../template.hpp"
#else
#define dbg(...) 0
#endif

const int INF = 1e9;
const int MxN = 200020;
vector<pair<int, int>> adj[MxN];

struct A{
	int value, dist_hospital, dist_center;
	A(int a, int b, int c){
		value = a;
		dist_hospital = b;
		dist_center = c;
	}
};

bool isCenter[MxN], isHospital[MxN];
int res = 0;

A dfs(int u, int p){
	A current(-INF, (isHospital[u] ? 0: -INF), (isCenter[u] ? 0: -INF));
	for(auto [x, w]: adj[u]){
		if(x == p){
			continue;
		}
		A now = dfs(x, u);
		current.value = max({current.value, current.dist_center + now.dist_hospital + w, current.dist_hospital + now.dist_center + w});
		current.dist_hospital = max(current.dist_hospital, now.dist_hospital + w);
		current.dist_center = max(current.dist_center, now.dist_center + w);
	}
	res = max(res, current.value);
	return current;
}

int furthest(int N, int H, int K, int roads[][2], int lengths[], int hospitals[], int centers[]){
	for(int i=0; i<N-1; ++i){
		adj[roads[i][0]].emplace_back(roads[i][1], lengths[i]);
		adj[roads[i][1]].emplace_back(roads[i][0], lengths[i]);
	}
	for(int i=0; i<H; ++i){
		isHospital[hospitals[i]] = true;
	}
	for(int i=0; i<K; ++i){
		isCenter[centers[i]] = true;
	}
	dfs(0, -1);
	return res;
}

#ifdef _DEBUG

static const int MAX_N = 200010;
static int N, H, K;
static int roads[MAX_N][2];
static int lengths[MAX_N];
static int hospitals[MAX_N];
static int centers[MAX_N];

int main(){
	freopen("sample.in", "r", stdin);
//	freopen("sample_1.in", "r", stdin);
	cin >> N >> H >> K;
	for(int i=0; i<H; ++i){
		cin >> hospitals[i];
	}
	for(int i=0; i<K; ++i){
		cin >> centers[i];
	}
	for(int i=0; i<N-1; ++i){
		cin >> roads[i][0] >> roads[i][1] >> lengths[i];
	}
	cout << furthest(N, H, K, roads, lengths, hospitals, centers) << "\n";
	return 0;
}
#endif
