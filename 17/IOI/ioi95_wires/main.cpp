#include "wirelib.h"

#include <bits/stdc++.h>
using namespace std;

const int MxN = 111;
int sol[MxN], n;

bitset<MxN> ok;

void calc(int l, int r, vector<int> v){
	if(l == r){
		for(auto x: v){
			sol[x] = r;
		}
		return ;
	}
	int mid = (l + r) >> 1;
	for(int i=l; i<=mid; ++i){
		if(!ok[i]){
			ok[i] = cmd_C(i);
		}
	}
	for(int i=mid + 1; i<=r; ++i){
		if(ok[i]){
			ok[i] = cmd_C(i);
		}
	}
	vector<int> resL, resR;
	for(auto x: v){
		if(cmd_T(x)){
			resL.push_back(x);
		}
		else{
			resR.push_back(x);
		}
	}
	calc(l, mid, resL);
	calc(mid + 1, r, resR);
}

int main(){
	n = wire_init();
	vector<int> v;
	for(int i=1; i<=n; ++i){
		v.push_back(i);
	}	
	calc(1, n, v);
	cmd_D(sol);
	return 0;
}
