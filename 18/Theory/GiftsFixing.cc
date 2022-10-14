#include <bits/stdc++.h>
using namespace std;

long long a[55], b[55];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		long long res = 0ll;
		scanf("%d", &n);
		for(int i=1; i<=n; ++i){
			scanf("%lld", &a[i]);
		}
		for(int i=1; i<=n; ++i){
			scanf("%lld", &b[i]);
		}
		long long min_a = *min_element(a + 1, a + n + 1);
		long long min_b = *min_element(b + 1, b + n + 1);
		for(int i=1; i<=n; ++i){
			res = res + max(a[i] - min_a, b[i] - min_b);
		}
		printf("%lld\n", res);
	}
	return 0;
}
