/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o62_oct_c2_customers
 * ALGO		: Square Root Decomposition
 * DATE		: 6 Feb 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 120010 * 2;
const int SQ = 490;

vector<int> shop[MxN], customer[MxN];
int cus[MxN], last[MxN];
bitset<MxN> ok;

void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1, sz; i<=m; ++i){
		cin >> sz;
		for(int j=0, x; j<sz; ++j){
			cin >> x;
			if(sz <= SQ){
				ok[i] = true;
				shop[i].push_back(x);
			}
			else{
				customer[x].push_back(i);
			}
		}
	}
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int x, y;
			cin >> x >> y;
			int to_add = y - last[x];
			if(ok[x]){
				for(auto a: shop[x]){
					cus[a] += to_add;
				}
			}
			last[x] = y;
		}
		else{
			int z;
			cin >> z;
			int res = cus[z];
			for(auto x: customer[z]){
				res += last[x];
			}
			cout << res << "\n";
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
