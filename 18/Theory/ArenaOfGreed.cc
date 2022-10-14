#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long long n, a[2] = {0, 0}, t=0;
		scanf("%lld", &n);
		while(n > 0){
			if(n % 2 == 0 && ((n / 2) % 2 == 1 || n == 4)){
				a[t] += n / 2;
				n /= 2;
			}	
			else{
				a[t] += 1;
				n -= 1;
			}
			t = !t;
		}
		printf("%lld\n", a[0]);
	}
	return 0;
}
