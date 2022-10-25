#include "symbols.h"
#include <bits/stdc++.h>

const long long MOD = 20232566;
const int MxN = 80080;

int n;
bool too_big = false;

struct segment_tree{

	int tree[MxN << 2];

	void build(int l, int r, int idx){
		if(l > r){
			continue;
		}
		if(l == r){
			tree[idx] = 1;
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
	}

	void push_lazy(int l, int r, int idx){
		if(!is_lazy[idx]){
			return ;
		}

		is_lazy[idx] = false;
	}
	
	void update(int l, int r, int wl, int wr, int value, int idx){
		if(l > r || r < wl || l > wr){
			return ;
		}
		push_lazy(l, r, idx);
		if(wl <= l && r <= wr){
			tree[idx] = make_pair(tree[idx].first - value,);
			if(l != r){
				is_lazy[idx] = true;
			}
			return ;
		}
		push_lazy(l, r, idx);
	}
} seg[27];

long long mop(int a, int b){
	if(b == 0){
		return 1ll;
	}
	if(a == 1){
		return 1ll;
	}
	long long t = mop(a, b / 2);
	t = (t * t) % MOD;
	if(b % 2){
		t = (t * a) % MOD;
	}
	return t;
}


void explore_site(int N, int Q) {
	n = N;
	seg[26].build();
}

int retrieve_notes(int L, int R) {
	if(R - L + 1 > 26){
		too_big = true;		
	}
	if(too_big){
		return 0;
	}
}
