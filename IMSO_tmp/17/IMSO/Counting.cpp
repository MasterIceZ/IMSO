/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Counting
 * ALGO		: Implementation
 * DATE		: 16 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for(int i=1; i<=n; ++i){
	}
	int it = 0;
	while(!q.empty()){
		++it;
		if(it == k){
			cout << q.front() << "\n";
			q.pop();
		}
		else{
			q.push(q.front());
			q.pop();
		}
		it %= k;
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
