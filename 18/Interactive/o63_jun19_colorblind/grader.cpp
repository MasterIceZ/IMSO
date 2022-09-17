#include "colorblind.h"
#include <iostream>

int NUMBER_OF_MONKEYS, NUMBER_OF_CALLS;

int use_device(int a, int b) {
	
	if(a < 0 || NUMBER_OF_MONKEYS <= a || b < 0 || NUMBER_OF_MONKEYS <= b) {
		printf("Wrong Answer: illegal call\n");
		exit(0);
	}

	if(a == b) {
		printf("Wrong Answer: illegal call\n");
		exit(0);
	}

	NUMBER_OF_CALLS++;

	printf("Swap %d and %d: ",a,b);
	int res; scanf("%d", &res);
	return res;
}

int main() {

	//////////// run multiple tests ////////////

	int T; scanf("%d",&T);

	while(T--) {

		//////////////// get input ////////////////

		int N; std::string S;
		std::cin >> N >> S;

		NUMBER_OF_MONKEYS = 2 * N;

		////////////////// solve //////////////////

		NUMBER_OF_CALLS = 0;
		std::string ret = investivate_colors(N);
		
		if(ret != S) {
			printf("Wrong Answer: incorrect\n");
			exit(0);
		}
		
		printf("Accepted: %d\n",NUMBER_OF_CALLS);
	}

	return 0;
}
