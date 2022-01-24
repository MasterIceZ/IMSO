/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Backup
 * ALGO		: Linked List, Greedy
 * DATE		: 22 Jan 2022
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

struct A{
	int value, idx;
	A(int a=0, int b=0): value(a), idx(b){}
	bool operator < (const A& o) const{
		return value > o.value;
	}
};

int a[MxN];
int l[5 * MxN], r[5 * MxN], value[5 * MxN];
priority_queue<A> pq;
bitset<5 * MxN> deleted;

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		value[i - 1] = a[i] - a[i - 1];
	}
	for(int i=1; i<n; ++i){
		pq.emplace(value[i], i);
		l[i] = i - 1;
		r[i] = i + 1;
	}
	value[0] = value[n] = 1e9 + 100;
	r[n] = n;
	int ptr = n;
	int answer = 0;
	while(k--){
		A now;
		while(!pq.empty()){
			now = pq.top();
			pq.pop();
			int idx = now.idx;
			if(!deleted[idx]){
				break;
			}
		}
		answer += now.value;
		int idx = now.idx;
		deleted[l[idx]] = deleted[r[idx]] = true;
		// Create New Node
		value[++ptr] = value[l[idx]] + value[r[idx]] - now.value;
		l[ptr] = l[l[idx]];
		r[l[ptr]] = ptr;
		r[ptr] = r[r[idx]];
		l[r[ptr]] = ptr;
		pq.emplace(value[ptr], ptr);
	}
	cout << answer;
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
