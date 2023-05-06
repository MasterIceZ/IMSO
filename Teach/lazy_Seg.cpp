#include <bits/stdc++.h>
using namespace std ;

struct Node{
	int value;
	bool active;
	int maxx, minn, sum;
	Node(int _value):
		value(_value), active(true), maxx(_value), minn(_value), sum(_value) {}
	Node():
		value(0), active(false), maxx(-1e9 - 100), minn(1e9 + 100), sum(0) {}
	Node operator + (const Node A, const Node B){
		Node res;
		res.active = true;
		res.value = -1;
		res.maxx = max(A.maxx, B.maxx);
		res.minn = min(A.minn, B.minn);
		res.sum = A.sum + B.sum;
		return res;
	}
};

Node tree[MxN];

void build(int l, int r, int idx){
	if(l > r){
		return ;
	}
	if(l == r){
		tree[idx] = Node(a[l]);
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, idx << 1);
	build(mid + 1, r, idx << 1 | 1);
	tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

inline void push_lazy(int l, int r, int idx){

}

void update(int l, int r, int wl, int wr, int idx){
	
}

Node query(int l, int r, int wl, int wr, int idx){

}

int main() {
	return 0;
}
