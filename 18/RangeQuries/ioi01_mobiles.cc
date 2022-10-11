/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: ioi01_mobiles
 * ALGO		: Fenwick Tree
 * DATE		: 10 Oct 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 2048;

int n;
struct fenwick_tree{
	int tree[MxN][MxN];
	void update(int idx_i, int idx_j, int v){
		for(int i=idx_i; i<=n; i+=i&-i){
			for(int j=idx_j; j<=n; j+=j&-j){
				tree[i][j] += v;
			}
		}
	}
	int read(int idx_i, int idx_j){
		int res = 0;
		for(int i=idx_i; i; i-=i&-i){
			for(int j=idx_j; j; j-=j&-j){
				res = res + tree[i][j];
			}
		}
		return res;
	}
} fw;

inline void solution(){
	while(1){
		int o;
		cin >> o;
		if(o == 0){
			cin >> n;
		}
		else if(o == 1){
			int x, y, a;
			x++, y++;
			cin >> x >> y >> a;
			fw.update(x, y, a);
		}
		else if(o == 2){
			int a, b, x ,y;
			cin >> a >> b >> x >> y;
			a++, b++, x++, y++;
			cout << fw.read(x, y) + fw.read(a - 1, b - 1) - fw.read(a - 1, y) - fw.read(x, b - 1) << "\n" << flush;
		}
		else{
			return ;
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
