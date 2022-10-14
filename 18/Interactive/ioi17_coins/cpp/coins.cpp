#include "coins.h"
#include <vector>

using namespace std;

std::vector<int> coin_flips(std::vector<int> b, int c) {
	int xored = 0;
	for(int i=0; i<64; ++i){
		if(b[i] == 1){
			xored = xored ^ i;
		}
	}
	return {c ^ xored};
}

int find_coin(std::vector<int> b) {
	int res = 0;
	for(int i=0; i<64; ++i){
		if(b[i] == 1){
			res = res ^ i;
		}
	}
    return res;
}
