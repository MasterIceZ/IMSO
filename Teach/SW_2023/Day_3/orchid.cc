#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v(n), dp; // create array with size n
	// index 0, ..., n - 1
	for(auto &x: v){
		scanf("%d", &x);
	} // 0, ..., n - 1
	for(auto x: v){
		int idx = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
		if((int) dp.size() == idx){
			dp.emplace_back(x);
		}
		else{
			dp[idx] = x;
		}
	}
	printf("%d\n", n - (int) dp.size());
	return 0;
}
