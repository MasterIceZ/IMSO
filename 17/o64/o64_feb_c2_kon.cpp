/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o64_feb_c2_kon
 * ALGO		: Math
 * DATE		: 16 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

vector<int> v;
void calc(int& n, int i){
	while(n % i == 0){
		n /= i;
		v.push_back(i);
	}
}

void solve(){
	int n;
	cin >> n;
	calc(n, 4);
	calc(n, 6);
	for(int i=2; i<=sqrt(n); ++i){
		if(n % i == 0){
			calc(n, i);
		}
	}
	if(n != 1){
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for(auto x: v){
		cout << "AC";
		for(int i=1; i<=x; ++i){
			cout << "V";
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
		cout << "\n";
	}
	return 0;
}
