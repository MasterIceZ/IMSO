/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o59_may02_topswops
 * ALGO		: Implicit Treap
 * DATE		: 3 Nov 2022
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

struct item{
	int prior, value, cnt;
	bool rev;
	struct item *l, *r;
	item(int _value):
		prior(rand()), value(_value), cnt(1), rev(false), l(NULL), r(NULL) {}
};
typedef item* pitem;

int cnt(pitem it){
	return it ? it->cnt: 0;
}
void update_cnt(pitem it){
	if(it != NULL){
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
	}
}
void push(pitem it){
	if(it != NULL && it->rev){
		it->rev = false;
		swap(it->l, it->r);
		if(it->l){
			it->l->rev ^= true;
		}
		if(it->r){
			it->r->rev ^= true;
		}
	}
}
void merge(pitem &t, pitem l, pitem r){
	push(l); push(r);
	if(l == NULL || r == NULL){
		t = l ? l: r;
	}
	else if(l->prior > r->prior){
		merge(l->r, l->r, r);
		t = l;
	}
	else{
		merge(r->l, l, r->l);
		t = r;
	}
	update_cnt(t);
}
void split(pitem t, pitem &l, pitem &r, int key, int add=0){
	if(t == NULL){
		l = r = NULL;
		return ;
	}
	push(t);
	int current_key = add + cnt(t->l);
	if(key <= current_key){
		split(t->l, l, t->l, key, add);
		r = t;
	}
	else{
		split(t->r, r->r, r, key, add + 1 + cnt(t->l));
		l = t;
	}
	update_cnt(t);
}
void reverse(pitem t, int l, int r){
	pitem t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r-l+1);
	t2->rev ^= true;
	merge(t, t1, t3);
	merge(t, t, t3);
}

int dfs(pitem u){
	push(u);
	if(u->l == NULL){
		return u->value;
	}
	return dfs(u->l);
}

inline void solution(){
	int n;
	cin >> n;
	
	pitem treap;

	for(int i=1, x; i<=n; ++i){
		cin >> x;
		merge(treap, treap, new item(x));
	}	
	int cnt = 0, k = dfs(treap);
	while(k != 1){
		cnt++;
		pitem a, b;
		split(treap, a, b, k);
		a->rev = true;
		merge(treap, a, b);
		k = dfs(treap);
	}
	cout << cnt;
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
