/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Distinct Values Queries
 * ALGO		:
 * DATE		:
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

template<class T> 
class fenwick_tree{
private:
	std::vector<T> ft;
	size_t n;
	int min(int a, int b){
		return (a < b ? a: b);
	}
public:
	fenwick_tree(size_t N){
		n = N;
		ft.resize(1024 + N);
	}
	inline void update(size_t idx, T value){
		for(; idx<=n; idx+=idx&-idx){
			ft[idx] += value;
		}
	}
	inline T query(size_t idx){
		T now = 0;
		for(; idx; idx-=idx&-idx){
			now += ft[idx];
		}
		return now;
	}
	inline void build(std::vector<int> v){
		for(int i=0; i<=min(n, (int) v.size() - 1); ++i){
			ft[i] += v[i];
			if(i + (i & -i) <= min(n, (int) v.size() - 1)){
				ft[i + (i & -i)] += ft[i];
			}
		}
	}
};

struct query_t{
	int l, r, idx;
	bool operator < (const query_t& other) const {
		return r < other.r;
	}
	query_t(int _l, int _r, int _idx):
		l(_l), r(_r), idx(_idx) {}
};

const int MxN = 200020;
int a[MxN], answer[MxN];
fenwick_tree<int> fw(MxN);
vector<query_t> qry;
int done[MxN];

inline void solution(){
	int n, q;
	cin >> n >> q;
	vector<int> c;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		c.emplace_back(a[i]);
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for(int i=1; i<=n; ++i){
		a[i] = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
	}
	for(int i=1, l, r; i<=q; ++i){
		cin >> l >> r;
		qry.emplace_back(l, r, i);
	}
	sort(qry.begin(), qry.end());
	for(int i=1; i<=n; ++i){
		if(done[a[i]]){
			fw.update(done[a[i]], -1);
		}	
		done[a[i]] = i;
		fw.update(i, 1);
		while(!qry.empty() && qry.back().r == i){
			answer[qry.back().idx] = fw.query(qry.back().r) - fw.query(qry.back().l - 1);
			qry.pop_back();
		}
	}
	for(int i=1; i<=q; ++i){
		cout << answer[i] << "\n";
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
