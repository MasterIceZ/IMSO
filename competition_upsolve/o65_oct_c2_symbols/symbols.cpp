#include <bits/stdc++.h>
#include "symbols.h"

using namespace std;

using ll = long long;

const ll MOD = 20232566ll;
const int MxN = 80080;
int N, Q;
ll ways[30];
bool can = true;
set<int> distinct[MxN];

ll mul(ll a, ll b){
	if(a == 1ll || b == 0ll){
		return 1ll;
	}
	if(b == 1ll){
		return a;
	}
	ll t = mul(a, b >> 1ll);
	t = (t * t) % MOD;
	if(b & 1ll){
		t = (t * a) % MOD;
	}
	return t;
}

void explore_site(int N, int Q) {
  ::N = N;
  ::Q = Q;
  ways[26] = N;
}

int retrieve_notes(int L, int R) {
	if(!can){
		return 0;
	}
	if(R - L + 1 > 26){
		can = false;
		return 0;
	}
	L++, R++;
	for(int i=L; i<=R; ++i){
		for(int j=i+1; j<=R; ++j){
			ways[26 - (int) distinct[j].size()]--;
			distinct[j].emplace(i);
			ways[26 - (int) distinct[j].size()]++;
		}
	}
	for(int i=L; i<=R; ++i){
		if((int) distinct[i].size() > 26){
			can = false;
		}
	}
	ll res = 1ll;
	for(ll i=1; i<=26ll; ++i){
		res = (res * mul(i, ways[i])) % MOD;
	}
	return res;
}
