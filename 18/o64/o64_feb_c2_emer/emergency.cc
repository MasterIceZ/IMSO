/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o64_feb_c2_emer
 * ALGO		: Depth First Search, Tree
 * DATE		: 20 Sep 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

#include "emergency.h"

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

struct City{
	int dist, to_center, to_hospital;
	City(int _dist, int _to_center, int _to_hospital):
		dist(_dist), to_center(_to_center), to_hospital(_to_hospital) {}
};

const int MxN = 200020;
vector<pair<int, int>> adj[MxN];
bool isHospital[MxN], isCenter[MxN];
int maxx = 0;

City dfs(int u, int p){
	City current_city(
		-1e9 - 100, 
		isCenter[u] ? 0: -1e9 - 100, 
		isHospital[u] ? 0: -1e9 - 100
	);
	for(auto x: adj[u]){
		if(x.first == p){
			continue;
		}
		City next_city = dfs(x.first, u);
		current_city.dist = max({
			current_city.dist,
			current_city.to_center + next_city.to_hospital + x.second,
			current_city.to_hospital + next_city.to_center + x.second
		});
		current_city.to_center = max(
			current_city.to_center,
			next_city.to_center + x.second
		);
		current_city.to_hospital = max(
			current_city.to_hospital,
			next_city.to_hospital + x.second
		);
	}
	maxx = max(maxx, current_city.dist);
	return current_city;
}

int furthest(int N, int H, int K,
	     int roads[][2],
	     int lengths[],
	     int hospitals[],
	     int centers[])
{
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
	return maxx;
}

#ifdef _DEBUG

#include "emergency.h"
#include <cstdio>

static const int MAX_N = 200010;
static int N, H, K;
static int roads[MAX_N][2];
static int lengths[MAX_N];
static int hospitals[MAX_N];
static int centers[MAX_N];

int main()
{
  scanf("%d %d %d",&N,&H,&K);
  for(int i=0; i<H; i++) {
    scanf("%d",&hospitals[i]);
  }
  for(int i=0; i<K; i++) {
    scanf("%d",&centers[i]);
  }
  for(int i=0; i<N-1; i++) {
    scanf("%d %d %d",&roads[i][0], &roads[i][1], &lengths[i]);
  }
  printf("%d\n",furthest(N, H, K,
			 roads, lengths,
			 hospitals, centers));
}

#endif

// https://github.com/MasterIceZ/archive/tree/main/cpp-template
