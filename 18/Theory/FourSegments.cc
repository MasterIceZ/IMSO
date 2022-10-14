#include <bits/stdc++.h>
using namespace std;

int a[5];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &a[1], &a[2], &a[3], &a[4]);
		sort(a + 1, a + 5);
		printf("%d\n", a[1] * a[3]);
	}
	return 0;
}
