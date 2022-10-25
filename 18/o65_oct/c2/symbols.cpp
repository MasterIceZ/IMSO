#include "symbols.h"
#include <set>
#include <bitset>
#include <cstdbool>

const int MOD = 20232566;
const int MxN = 80080;

int n;
std::set<int> adj[MxN];
bool too_much = false;

void explore_site(int N, int Q) {
	n = N;
}

int retrieve_notes(int L, int R) {
	if(too_much){
		return 0;
	}
	if(R - L + 1 > 26){
		too_much = true;
		return 0;
	}
	for(int i=L; i<R; ++i){
		if(too_much){
			break;
		}
		for(int j=i+1; j<=R; ++j){
			if(adj[j].size() >= 26){
				too_much = true;
				break;
			}
			adj[j].emplace(i);
		}
	}
	if(too_much){
		return 0;
	}
	int r = 1;
	for(int i=0; i<n; ++i){
		r = (r * (26 - (int) adj[i].size())) % MOD;
	}
	return r;
}
