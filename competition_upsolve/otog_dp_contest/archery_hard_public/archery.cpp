#include <bits/stdc++.h>
#include "archery.h"

using namespace std;

priority_queue<long long> le;
priority_queue<long long, vector<long long>, greater<long long>>ri;
long long lle, lri;

long long minPenguinCoin(int N, std::vector<int> A, std::vector<int> U, std::vector<int> D){
	long long res = 0ll;
	for(int i=0; i<N; ++i){
		if(i == 0){
			le.push(A[i]);
			ri.push(A[i]);
		}
		else{
			lle -= D[i - 1];
			lri += U[i - 1];
			if(A[i] <= le.top() + lle){
				res += le.top() + lle - A[i];
				ri.push(le.top() + lle - lri);
				le.pop();
				le.push(A[i] - lle);
				le.push(A[i] - lle);
			}
			else if(A[i] >= ri.top() + lri){
				res += A[i] - ri.top() - lri;
				le.push(ri.top() + lri - lle);
				ri.pop();
				ri.push(A[i] - lri);
				ri.push(A[i] - lri);
			}
			else{
				le.push(A[i] - lle);
				ri.push(A[i] - lri);
			}
		}
	}
    return res;
}
