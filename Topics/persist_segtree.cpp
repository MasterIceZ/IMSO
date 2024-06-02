struct node_t;
using pnode_t = node_t *;

struct node_t {
	int v;
	pnode_t l, r;
	node_t(int _v):
		v(_v), l(nullptr), r(nullptr);
};

void build(int l, int r, pnode_t &cur) {
	cur = new node_t(0);
	if(l == r) {
		cur->v = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, cur->l);
	build(mid + 1, r, cur->r);
	cur->v = cur->l->v + cur->r->v;
}

void update(int l, int r, int id, int v, pnode_t &cur, pnode_t pre) {
	cur = new node_t(*pre);
	if(l == r) {
		cur->v += v;
		return ;
	}
	int mid = (l + r) >> 1;
	if(id <= mid) {
		update(l, mid, id, v, cur->l, pre->l);
	}
	else {
		update(mid + 1, r, id, v, cur->r, pre->r);
	}
	cur->v = cur->l->v + cur->r->v;
}
