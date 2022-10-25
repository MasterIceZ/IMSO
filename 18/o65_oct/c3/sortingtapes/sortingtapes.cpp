#include "sortingtapes.h"
#include <bits/stdc++.h>

// 20.69
// std::vector<int> sort_tapes(int N, std::vector<int> A, std::vector<int> B) {
// 	std::vector<int> C;
// 	int i=0, j=0;
// 	while(i<N && j<N){
// 		if(compare(A[i], B[j])){
// 			C.emplace_back(A[i++]);
// 		}
// 		else{
// 			C.emplace_back(B[j++]);
// 		}
// 	}	
// 	while(i<N){
// 		C.emplace_back(A[i++]);
// 	}
// 	while(j<N){
// 		C.emplace_back(B[j++]);
// 	}
// 	return C;
// }

std::vector<int> sort_tapes(int N, std::vector<int> A, std::vector<int> B) {
	std::vector<int> C;
	int i = 0, j = 0;

	if(compare(A.back(), B[0])){
		while(i<N){
			C.emplace_back(A[i++]);
		}
		while(j<N){
			C.emplace_back(B[j++]);
		}
		return C;
	}
	if(!compare(A[0], B.back())){
		while(j<N){
			C.emplace_back(B[j++]);
		}
		while(i<N){
			C.emplace_back(A[i++]);
		}
		return C;
	}
	while(i<N && j<N){
		if(compare(A[i], B[j])){
			C.emplace_back(A[i++]);
		}
		else{
			C.emplace_back(B[j++]);
		}
	}	
	while(i<N){
		C.emplace_back(A[i++]);
	}
	while(j<N){
		C.emplace_back(B[j++]);
	}
	return C;
}
