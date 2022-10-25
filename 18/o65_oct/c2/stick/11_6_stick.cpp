#include "stick.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 88;
int a[MxN];

void init(int N, std::vector<int> X){
	if(N > 80){
		exit(0);
	}
	for(int i=1; i<=N; ++i){
		a[i] = X[i - 1];
	}
	return ;
}

int max_length(int L,int R){
	int res = -1;
	L++, R++;
//	cerr << "----------------\n";
	for(int i=L; i<=R; ++i){
		for(int j=i+1; j<=R; ++j){
			for(int k=j+1; k<=R; ++k){
				int all = a[i] + a[j] + a[k];
				int two = all - max({a[i], a[j], a[k]});
				int maxx = all - two;
//				cerr << "A : " << a[i] << " " << a[j] << " " << a[k] << "\n"; 
//				cerr << "D : " << maxx << " " << two << "\n";
				if(maxx < two){
					res = max(res, all);
				}
			}
		}
	}
	return res;
}
