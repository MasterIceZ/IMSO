/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: woods
 * ALGO		: Sweepline
 * DATE		: 16 Nov 2022
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

struct Event{
	int idx, state, r;
	bool operator < (const Event& o) const {
		if(r != o.r){
			return r < o.r;
		}
		return state < o.state;
	}
	Event(int _idx, int _state, int _r):
		idx(_idx), state(_state), r(_r) {}
};

inline void solution(){
	int n, w, l;
	cin >> n >> w >> l;
	vector<Event> line;
	for(int i=0, z; i<n; ++i){
		cin >> z;
		for(int j=1, x; j<=z; ++j){
			cin >> x;
			line.emplace_back(i, 1, x - l);
			line.emplace_back(i, 0, x + l + 1);
		}
	}
	vector<int> now(n), wanted(n, 1);
	sort(line.begin(), line.end());
	bool ok = false;
	for(auto x: line){
		if(x.state == 0){
			now[x.idx]--;
		}
		else{
			now[x.idx]++;
		}
		ok |= (now == wanted);
	}
	cout << ok;
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
