/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct13_lightest
 * ALGO		: Heap
 * DATE		: 7 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Hat{
	int w, v;
	bool operator < (const Hat& o) const{
		return w > o.w;
	}
};

priority_queue<Hat> pq;

void solve(){
	int n, m, q, x, y;
	cin >> n >> m;
	q = n + m;
	char opr;
	while(q--){
		cin >> opr;
		if(opr == 'T'){
			cin >> x >> y;
			pq.push({x, y});
		}
		else{
			if(pq.empty()){
				cout << 0 << "\n";
			}
			else{
				cout << pq.top().v << "\n";
				pq.pop();
			}
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
