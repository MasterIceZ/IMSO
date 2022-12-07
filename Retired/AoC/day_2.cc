#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char A, B;

inline int play(char a, char b){
	if(A - 'A' == B - 'X'){
		return 0;
	}
	if(A == 'A' && B == 'Y'){
		return 1;
	}
	if(A == 'B' && B == 'Z'){
		return 1;
	}
	if(A == 'C' && B == 'X'){
		return 1;
	}
	return -1;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	int pts = 0;
	int n = 2500;
	char C;
	int w;
	for(int i=1; i<=n; ++i){
		cin >> A >> C;
		if(C == 'X'){
			pts += 0;
			w = -1;
		}
		else if(C == 'Y'){
			pts += 3;
			w = 0;
		}
		else{
			pts += 6;
			w = 1;
		}
		B = 'X';
		while(play(A, B) != w){
			B++;
		}
		pts += (B - 'X' + 1);
	}
	cout << pts;
	return 0;
}
