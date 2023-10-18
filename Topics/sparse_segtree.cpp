#include <bits/stdc++.h>

using namespace std;

struct node_t {
	int val;
	node_t *l, *r;
	node_t(int _val=-1e9-100):
		val(_val), l(nullptr), r(nullptr) {}
};

node_t merge_node(node_t l, node_t r) {
	return l.val + r.val;
}

struct segment_tree {
	using pnode_t = node_t*;
	node_t *r;
	void update(int l, int r, int id, int val, pnode_t &idx) {
		if(l > r) {
			return ;
		}
		if(idx == nullptr) {
			idx = new node_t(val);
		}
		if(l == r) {
			idx->val = 	
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, val, idx->l);
		update(mid + 1, r, id, val, idx->r);
		idx = merge_node(idx->l, idx->r);
	}
	void update(int l, int r, int id, int val) {
		update(l, r, id, val, r);
	}
	segment_tree():
		r(nullptr) {}
}

int main() {
	return 0;
}
