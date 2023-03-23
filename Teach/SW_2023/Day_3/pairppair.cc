#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

pii operator + (const pii a, const pii b){
	pii res = {
		a.first + b.first,
		a.second + b.second
	};
	return res;
}

int main(){
	pair<int, int> a = {1, 2};
	pair<int, int> b = {2, 3};
	pair<int, int> sum = a + b;
	printf("sum = (%d, %d)", sum.first, sum.second);
	return 0;
}
