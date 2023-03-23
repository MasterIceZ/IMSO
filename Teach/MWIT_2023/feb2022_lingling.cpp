#include "lingling.h"
#include <vector>

std::vector<int> want;

void init_monkeys(std::vector<int> P, int Q){
	want = P;
}

long long minimum_branches(int L, int R){
	long long n = R - L;
	return n * (n + 1ll) / 2ll;
}
