#include <bits/stdc++.h>
#include "rumors.h"

using namespace std;


#ifdef _DEBUG
#include "../template.hpp"
#else
#define dbg(...) 0
#endif

const int MxN = 2020;
vector<int> dp[MxN];
int dist[MxN][MxN];

vector<int> analyze_rumors(int N, int K, int Q, vector<int> d, vector<int> x, vector<int> j) {
	int n = N;
	int k = K;
	dbg(n, k);
	for(int i=0; i<n; ++i){
		dp[i].push_back(0);
		for(int j=i+1; j<n; ++j){
			// Number of Reporters uses from i to j
			dist[i][j] = dist[i][j - 1] + (d[j] - d[j - 1] - 1) / k;
		}
	}
	int mxL = 0;
	for(int sz=2; sz<=n; ++sz){
		// Answer cluster[i]
		deque<pair<int, int>> dq;
		int l = 2;
		for(int i=0; i<n; ++i){
			int psx = i + sz - 1;
			while(!dq.empty() && dq.front().first < i){
				dq.pop_front();
			}
			if(psx < n){
				while(!dq.empty() && dq.back().second >= dist[i][psx]){
					dq.pop_back();
				}
				dq.emplace_back(psx, dist[i][psx]);
			}
//			dp[i][l++] = dq.front().second;
//			dbg(dp[i][l - 1], i, l - 1);
			dp[i].push_back(dq.front().second);
		}
	}
	vector<int> res;
	for(int i=0; i<Q; ++i){
//		int idx = upper_bound(dp[x[i]], dp[x[i]] + mxL, j[i]) - dp[x[i]];
		int idx = upper_bound(dp[x[i]].begin(), dp[x[i]].end(), j[i]) - dp[x[i]].begin();
		res.push_back(idx);
	}
	return res;
}

#ifdef _DEBUG
int main(){
	freopen("sample.in", "r", stdin);
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> D, X, J;
	for(int i=1, d; i<=n; ++i){
		cin >> d;
		D.push_back(d);
	}
	for(int i=1, x, j; i<=q; ++i){
		cin >> x >> j;
		X.push_back(x);
		J.push_back(j);
	}
	auto res = analyze_rumors(n, k, q, D, X, J);
	for(auto x: res){
		cout << x << "\n";
	}
	return 0;
}
#endif
