#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 20232566;
	for(int i=2; i*i<=n; ++i){
		while(n % i == 0 && n != 0){
			cout << i << " ";
			n /= i;
		}
	}
	if(n != 0){
		cout << n << " ";
	}
	cout << "\n";
	return 0;
}
