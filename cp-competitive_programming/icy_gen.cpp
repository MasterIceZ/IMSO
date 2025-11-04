#include "testlib.h"

#include <algorithm>

const int MxN = 1'000'000'000;

signed main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);

	int Q = opt<int> ("Q");
	int P = rnd.next(1, MxN);
	
	int ver = 0;
	std::cout << Q << "\n";
	while(Q--) {
		if(Q % 2 == 1) {
			int val = rnd.next(1, MxN);
			std::cout << "U " << P << " " << val;
			++ver;
		}
		else {
			int k = rnd.next(1, 3);
			if(k == 3) {
				int rp = rnd.next(std::max(0, ver - 5), ver);
				std::cout << "A " << P << " " << rp;
			}
			else {
				int pp = rnd.next(1, ver);
				std::cout << "A " << P << " " << pp;
			}
		}
		std::cout << "\n";
	}

	return 0;
}
