/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Crossing the Road
 * ALGO		: Dijkstra
 * DATE		: 19 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 55;
const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

struct Node{
	pair<int, int> pos;
	int w;
	inline bool operator < (const Node& o) const{
		return w > o.w;
	}
};

void solve(){

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
