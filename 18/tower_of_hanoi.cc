#include <bits/stdc++.h>
using namespace std;

int n;

// rec(number of disk, from, to, other)
void rec(int n, int from, int to, int other){
	cerr << "Current : " << n << ", " << from << ", " << to << ", " << other << "\n";
	if(n == 0){
		return ;
	}
	// move (n - 1) disks to other
	rec(n - 1, from, other, to);
	cout << n << " " << from << " " << to << "\n";
	// move (n - 1) disks to prefered rod
	rec(n - 1, other, to, from);
}

int main(){
	cin >> n;
	// want to move disk from 1 to 3
	rec(n, 1, 3, 2);
	return 0;
}
