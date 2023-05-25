#include <bits/stdc++.h>
using namespace std;

const int MxN = 100010;
int p[MxN], h[MxN], v[MxN];

int find_root(int u){
	if(u == p[u]){
		return u;
	}
	int parent = find_root(p[u]);
	h[u] = h[p[u]] - 1;
	return parent;
}

int main(){
	int n, q, t, x, y, a, answer, rx, ry;
	scanf("%d %d", &n, &q);
	for(int i=1; i<=n; ++i){
		p[i] = i;
		h[i] = 1;
	}
	while(q--){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d %d %d", &x, &y, &a);
			rx = find_root(x);
			ry = find_root(y);
			if(h[rx] > h[ry]){
				h[rx] = max(h[rx], h[ry] + 1);
				p[ry] = rx;
				v[ry] = max(v[rx], v[ry]);
				v[rx] = a;
			}
			else{
				h[ry] = max(h[ry], h[rx] + 1);
				p[rx] = ry;
				v[rx] = max(v[rx], v[ry]);
				v[ry] = a;
			}
		}
		else{
			scanf("%d %d", &x, &y);
			rx = find_root(x);
			ry = find_root(y);
			answer = 0;
			if(rx == ry){
				if(h[x] > h[y]){
					swap(x, y);
				}
				while(h[x] < h[y]){
					answer = max(answer, v[x]);
					x = p[x];
				}
				if(x == y){
					printf("%d\n", answer);
					continue;
				}
				while(x != y){
					answer = max({answer, v[x], v[y]});
					x = p[x];
					y = p[y];				
				}
				printf("%d\n", answer);
			}
			else{
				printf("%d\n", max(v[rx], v[ry]));
			}
		}
	}
	return 0;
}
