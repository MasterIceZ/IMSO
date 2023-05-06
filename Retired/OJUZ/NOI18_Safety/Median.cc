#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 200020;
double a[MxN], h, answer = 0.0;

int main(){
	int n;
	scanf("%d %lf", &n, &h);
	for(int i=1; i<=n; ++i){
		scanf("%lf", &a[i]);
	}
	sort(a + 1, a + n + 1);
	double median = a[n / 2];
	if(n % 2){
		median = median + a[(n - 1) / 2] / 2.0;
	}
	for(int i=1; i<=n; ++i){
		answer += abs(a[i] - median);	
	}
	printf("%.0lf\n", answer);
	return 0;
}
