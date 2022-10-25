#include "stick.h"
#include <bits/stdc++.h>

using namespace std;

struct Node{
	int first, second, third;
	Node(int _first=-1, int _second=-1, int _third=-1):
		first(_first), second(_second), third(_third) {}
};

const int MxN = 200020;
Node tree[MxN << 2], empty_node;
int a[MxN];

Node merge_node(Node a, Node b){
	Node res;
	int aa[] = {a.first, a.second, a.third};
	int bb[] = {b.first, b.second, b.third};
	int cc[] = {-1, -1, -1};
	for(int i=0, it=0, it2=0; i<3; ++i){
		if(aa[it] > bb[it2]){
			cc[i] = aa[it++]; 
		}
		else{
			cc[i] = bb[it2++];
		}
	}
	res.first = cc[0];
	res.second = cc[1];
	res.third = cc[2];
	return res;
}

void build(int l, int r, int idx){
	if(l > r){
		return ;
	}
	if(l == r){
		tree[idx].first = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, idx << 1);
	build(mid + 1, r, idx << 1 | 1);
	tree[idx] = merge_node(tree[idx << 1], tree[idx << 1 | 1]);
}

Node query(int l, int r, int wl, int wr, int idx){
	if(l > r || l > wr || r < wl){
		return empty_node;
	}
	if(wl <= l && r <= wr){
		return tree[idx];
	}
	int mid = (l + r) >> 1;
	return merge_node(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
}

int N;

void init(int N, std::vector<int> X){
	::N = N;
	for(int i=0; i<N; ++i){
		a[i] = X[i];
		assert(1 <= a[i] && a[i] <= 500000000);
	}
	build(0, N - 1, 1);
	return ;
}

int max_length(int L,int R){
	assert(R - L > 1);
	Node now = query(0, N - 1, L, R, 1);
	if(now.first == -1 || now.second == -1 || now.third == -1){
		return -1;
	}
	if(now.first < now.second + now.third){
		return now.first + now.second + now.third;
	}
	return -1;
}
