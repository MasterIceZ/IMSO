#include<stdio.h>

int p[1000010];

// int find_root(int u){
// 	if(u == p[u]){
// 		return u;
// 	}
// 	return p[u] = find_root(p[u]);
// }

int main(){
	int n, m, q, pa, pb;
	scanf("%d %d %d", &n, &m, &q);
	for(int i=1; i<=n; ++i){
		p[i] = i;
	}
	while(m--){
		scanf("%d %d", &pa, &pb);
		pa = find_root(pa), pb = find_root(pb);
		if(pa != pb){
			p[pa] = pb;
		}
	}
	while(q--){
		scanf("%d %d", &pa, &pb);
		if(find_root(pa) == find_root(pb)){
			printf("Y\n");
		}
		else{
			printf("N\n");
		}
	}
	return 0;
}
