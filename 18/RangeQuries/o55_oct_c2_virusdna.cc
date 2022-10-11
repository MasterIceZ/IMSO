/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Virus DNA
 * ALGO		: Fenwick Tree
 * DATE		: 9 Oct 2022
 * */

#include <bits/stdc++.h>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 1000010;

struct fenwick_tree_2{
	int tree[MxN * 2];
	void update(int idx, int v){
		for(; idx<=2000000; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	int read(int idx){
		int res = 0;
		for(; idx>0; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} dna, all;

inline void solution(){
	int n, m, idx, l, r, mid, l2, r2, all_dna = 0, del_gab = 0;
	char o;
	cin >> n >> m;
	for(int i=1, all_i = 1; i<=n; ++i, all_i+=2){
//		dna.update(i, 1);
		all.update(all_i, 1);
	}
	for(int i=1; i<=m; ++i){
		cin >> o;
		if(o == 'g'){
			cin >> idx;
			idx++;
			l = 1, r = 2 * n;
			while(l < r){
				mid = (l + r) / 2;
				dbg(l, mid, r, all.read(mid));
				if(all.read(mid) >= idx){
					r = mid;
				}
				else{
					l = mid + 1;
				}
			}
			dbg(l);
			// now l is index to update
			if(l % 2 == 1){
				l++;
			}
			dbg("add", l);

			all.update(l, 1);
			dna.update(l, 1);

		}
		else if(o == 'd'){
			cin >> idx;
			idx++;
			l = 1, r = 2 * n;
			while(l < r){
				mid = (l + r) / 2;
				if(all.read(mid) >= idx){
					r = mid;
				}
				else{
					l = mid + 1;
				}
			}
			dbg("del", l);
			// real
			if(l % 2 == 1){
				dna.update(l, 1);
				all.update(l, -1);
			}
			else{
				dna.update(l, -1);
				all.update(l, -1);
			}
		}
		else{
			cin >> l >> r;
		//	all_dna = (r - l + 1) - (dna.read(r) - dna.read(l - 1));
		//	if(l == 0 || r == 0){
		//		while(1);
		//	}
		//	l2 = l * 2 - 1;
		//	r2 = r * 2 - 1;
		//	del_gab = all.read(r2) - all.read(l2 - 1) - (dna.read(r) - dna.read(l - 1));
		//	dbg(all_dna, del_gab);
		//	cout << all_dna + del_gab << "\n";
			cout << dna.read(r * 2 - 1) - dna.read(l * 2 - 2) << "\n";
		}
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
