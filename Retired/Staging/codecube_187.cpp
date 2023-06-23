#include <bits/stdc++.h>

using namespace std;

mt19937 rng(time

struct node_t {
	char val;
	int prio, sz;
	bool lazy;
	node_t *l, *r;
	node(char _val):
		val(_val), prio(rng()), sz(1), lazy(false), l(NULL), r(NULL) {}
};

struct treap_t {
	using pnode_t = node_t*;
	pnode_t root = NULL;
	
	int sz(pnode_t u) {
		if(u == NULL) {
			return 0;
		}
		return u->sz;
	}
	void update_sz(pnode_t u) {
		if(u == NULL){
			return ;
		}
		u->sz = sz(u->l) + sz(u->r) + 1;
	}
	void push_lazy(pnode_t u) {
		if(u == NULL || u->lazy == false){
			return ;
		}
		u->lazy = false;
		swap(u->l, u->r);
		if(u->l) {
			u->l->lazy ^= true;
		}
		if(u->r) {
			u->r->lazy ^= true;
		}
	}
	void merge(pnode_t &u, pnode_t ul, pnode_t ur) {
		push_lazy(ul); push_lazy(ur);
		if(ul == NULL) {
			u = ur;
			return ;
		}
		if(ur == NULL) {
			u = ul;
			return ;
		}
		if(ul->prio > ur->prio){
			merge(ul->r, ul->r, ur);
			u = ul;
			return ;
		}
		else{
			merge(ur->l, ul, ur->l);
			u = ur;
			return ;
		}
		update_sz(u);
	}
	void split(pnode_t u, pnode_t &ul, pnode_t &ur, int v) {

	}
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	string s;
	int q;
	cin >> s >> q;

	return 0;
}
