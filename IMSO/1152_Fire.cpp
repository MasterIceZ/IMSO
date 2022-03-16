/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Fire
 * ALGO		: Breadth First Search, Heap
 * DATE		: 25 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

struct Cell{
	int first, second, state;
};

struct A{
	int val, idx;
	bool operator < (const A& o) const{
		if(val != o.val){
			return val < o.val;
		}
		return idx < o.idx;
	}
};

const int MxN = 1010;
int a[MxN][MxN];
bitset<MxN> visited[MxN];
vector<int> adj[3 * MxN];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	queue<Cell> q;
	q.push({1, 1, 0});
	visited[1][1] = true;
	int MxS = 0;
	while(!q.empty()){
		Cell now = q.front();
		q.pop();
		adj[now.state].push_back(a[now.first][now.second]);
		MxS = max(MxS, now.state);
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > n){
				continue;
			}
			if(visited[ii][jj]){
				continue;
			}
			q.push({ii, jj, now.state + 1});
			visited[ii][jj] = true;
		}
	}
	priority_queue<A> pq;
	int ans = 0;
	for(int i=MxS; i>=1; --i){
		for(auto x: adj[i]){
			pq.push({x, i});
		}
		ans += pq.top().val;
		pq.pop();
	}
	cout << ans;
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
