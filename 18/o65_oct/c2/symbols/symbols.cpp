#include "symbols.h"
#include <set>
#include <bitset>
#include <cstdbool>
#include <iostream>

const int MOD = 20232566;
const int MxN = 80080;

int n;
std::set<int> adj[MxN];
bool too_much = false;
int cnt[33];

long long mod_of_power(int a, int b){
	if(b == 1){
		return a;
	}
	if(b == 0){
		return 1;
	}
	if(a == 1){
		return 1;
	}
	long long t = mod_of_power(a, b / 2);
	std::cerr << "X : " << a << " " << b << "\n";
	t = (t * t) % MOD;
	if(b % 2 == 1){
		t = (t * a) % MOD;
	}
	return t;
}

void explore_site(int N, int Q) {
	n = N;
	cnt[26] = N;
}

int retrieve_notes(int L, int R) {
	if(too_much){
		return 0;
	}
	if(R - L + 1 > 26){
		too_much = true;
		return 0;
	}
	std::cerr << "-----------------\n";
	for(int i=L; i<R; ++i){
		for(int j=i+1; j<=R; ++j){
			if(adj[j].size() >= 26){
				too_much = true;
				break;
			}
			cnt[26 - (int) adj[j].size()]--;
			adj[j].emplace(i);
			cnt[26 - (int) adj[j].size()]++;
		}
	}
	std::cerr << "??????\n";
	if(too_much){
		return 0;
	}
	for(int i=1; i<=26; ++i){
		if(cnt[i] != 0){
			std::cerr << i << " = " << cnt[i] << "\n";
		}
	}
	long long r = 1ll;
	for(int i=1; i<=26; ++i){
		if(cnt[i] == 0){
			continue;
		}
		r = (r * mod_of_power(i, cnt[i])) % MOD;
	}
	return r;
}
