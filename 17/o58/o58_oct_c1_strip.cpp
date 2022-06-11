/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o58_oct_c2_strip
 * ALGO		: Fenwick Tree
 * DATE		: 5 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;

struct Fenwick{
	int tree[MxN];
	void update(int idx, int v){
		for(; idx<=100001; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw;

vector<pair<int, int>> line[MxN], query[MxN];
int answer[MxN];

void solve(){
	int n, m, k, x1, x2, y1, y2;
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		cin >> x1 >> y1 >> x2 >> y2;
		x1++, x2++, y1++, y2++;
		line[x1].emplace_back(y1, 1);
		line[x1].emplace_back(y2 + 1, -1);
		line[x2 + 1].emplace_back(y1, -1);
		line[x2 + 1].emplace_back(y2 + 1, 1);
	}
	for(int i=1, x, y; i<=m; ++i){
		cin >> x >> y;
		x++, y++;
		query[x].emplace_back(y, i);
	}
	for(int i=1; i<=100001; ++i){
		for(auto x: line[i]){
			fw.update(x.first, x.second);
		}
		for(auto x: query[i]){
			answer[x.second] = fw.read(x.first);
		}
	}
	for(int i=1; i<=m; ++i){
		cout << answer[i] << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
