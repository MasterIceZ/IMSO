#include <bits/stdc++.h>
using namespace std;

const int MxA = 1000010;
const int MxN = 200020;

struct fenwick_tree{
	int tree[MxA];
	void update(int idx, int value){
		for(; idx<=1000000; idx+=idx&-idx){
			tree[idx] = tree[idx] + value;
		}
	}
	int query(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res = res + tree[idx];
		}
		return res;
	}
} fw;

int a[MxN], b[MxN];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<n; ++i){
		scanf("%d", &b[i]);
	}
	for(int i=1; i<=n; ++i){
		printf("%d\n", i - fw.query(a[i]) - 1);
		if(i != n){
			fw.update(b[i], 1);
		}
	}
	return 0;
}
