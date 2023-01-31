#include <stdio.h>

const int MOD = 1e6 + 3;
const int MxN = 1e6 + 10;
const int MxM = 1e5 + 10;
char s[MxN];
int used[MOD], v[MOD];
bool visited[MxN], printed;

int main(){
	int n, m, q, i, j, sz, val;
	long long t, k; 
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; ++i){
		gets(s);
		for(j=0, t=0ll; j<m; ++j){
			t <<= 1ll;
			t |= (s[i] - '0');
		}
		k = t % MOD;
		while(used[k]){
			k = (k + 1ll) % MOD;
		}
		used[k] = i;
		v[k] = t;
	}
	long long cutter = 1 << (m - 1), ha;
	scanf("%d", &q);
	while(q--){
		scanf("%d", &sz);
		gets(s);
		ha = 0;
		for(i=0; i<m; ++i){
			ha = (ha << 1ll) | (s[i] - '0');
		}
		for(i=0; i<=sz-m; ++i){
			k = ha % MOD;
			val = 0;
			while(used[k]){
				if(v[k] == ha){
					val = used[k];
					break;
				}
				k = (k + 1ll) % MOD;
			}
			visited[val] = true;
			ha -= ((s[i] - '0') * cutter);
			ha = (ha << 1ll) | (s[i + m] - '0');
		}
		printed = false;
		for(i=1; i<=n; ++i){
			if(visited[i]){
				printf("%d ", i);
				printed = true;
			}
			visited[i] = false;
		}
		if(!printed){
			printf("OK");
		}
		printf("\n");
	}
	return 0;
}
