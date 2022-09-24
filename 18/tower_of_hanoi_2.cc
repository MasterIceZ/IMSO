#include <bits/stdc++.h>
using namespace std;

int n;

void rec(int n, int from, int to, int other){
	if(n == 0){
		return ;
	}
	if(from != 1 || other != 3){
		rec(n - 1, from, other, to);
	}
	cout << n << " " << from << " " << to << "\n";
	if(other != 1 || to != 3){
		rec(n - 1, other, to, from);
	}
}

int main(){
	cin >> n;
	rec(n, 1, 3, 2);
	return 0;
}
