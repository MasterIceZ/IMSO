/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: noodle
 * ALGO		: Binary Search, Heap
 * DATE		: 23 Dec 2021
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
int n, m, k;
ll a[MxN];
priority_queue<ll, vector<ll>, greater<ll>> pq;

void solve(){
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	ll l = 1, r = 1e18;
	ll sum = 0;
	while(l < r){
		ll mid = (l + r + 1) >> 1, cnt = 0;
		sum = 0;
//		mid = 15;
		while(!pq.empty()){
			pq.pop();
		}
		for(int i=1; i<=n; ++i){
			sum += a[i];
			pq.push(a[i]);
			dbg(pq.size());
			if(pq.size() >= k){
				if(sum >= mid){
//					dbg(l, r, mid, i, sum, cnt + 1);
					sum = 0;
					cnt++;
					while(!pq.empty()){
						pq.pop();
					}
				}
				else{
					sum -= pq.top();
					pq.pop();
				}
			}
		}
		dbg(cnt, l, r, mid);
		if(cnt >= m){
			l = mid;
		}
		else{
			r = mid - 1;
		}
//		break;
	}
	cout << l;
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
