/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: tracks
 * ALGO		: Breadth First Search
 * DATE		: 23 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Cell{
	int x, y, prio, idx;
	bool operator < (const Cell& o) const{
		if(prio != o.prio){
			return prio > o.prio;
		}
		return idx > o.idx;
	}
	Cell(int a, int b, int c, int d): x(a), y(b), prio(c), idx(d) {}
	Cell(int a, int b): x(a), y(b), prio(0), idx(0) {}
};

char op(char s){
	if(s == 'R'){
		return 'F';
	}
	if(s == 'F'){
		return 'R';
	}
	return '.';
}

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

const int MxN = 4040;
// priority_queue<Cell> pq;
char a[MxN][MxN];
bitset<MxN> visited[MxN];
deque<Cell> q;

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	int it = 1;
//	pq.emplace(1, 1, 1, it++);
	q.emplace_front(1, 1);
	visited[1][1] = true;
	int cnt = 0;
	char lst = op(a[1][1]);
	int last_prio = 1;
//	while(!pq.empty()){
//		Cell now = pq.top();
//		pq.pop();
//		if(visited[now.x][now.y]){
//			continue;
//		}
//		visited[now.x][now.y] = true;
	while(!q.empty()){
		Cell now = q.front();
		q.pop_front();
		dbg(now.x, now.y, now.prio, now.idx);
		if(a[now.x][now.y] != lst){
			cnt++;
			lst = op(lst);
		}
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.x;
			int jj = dj[k] + now.y;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(visited[ii][jj] || a[ii][jj] == '.'){
				continue;
			}
			if(a[ii][jj] == a[now.x][now.y]){
//				pq.emplace(ii, jj, now.prio, -1);
				q.emplace_front(ii, jj);
				visited[ii][jj] = true;
			}
			else{
//				pq.emplace(ii, jj, last_prio++, it++);
				q.emplace_back(ii, jj);
				visited[ii][jj] = true;
			}
		}
	}
	cout << cnt ;
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
