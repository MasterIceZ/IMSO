#include <cstdio>

#ifndef __LINEAR_SIEVE__
#define __LINEAR_SIEVE__

#include <vector>

struct linear_sieve {
	std::vector<bool> is_composite;
	std::vector<int> prime;
	size_t sz;

	inline void do_sieve() {
		for(size_t i=2; i<=sz; ++i) {
			if(!is_composite[i]) {
				prime.emplace_back(i);
			}
			for(size_t j=0; j<prime.size() && i * prime[j] <= sz; ++j) {
				is_composite[i * prime[j]] = true;
				if(i % prime[j] == 0) {
					break;
				}
			}
		}
	}

	linear_sieve(size_t _sz):
		sz(_sz) {
		is_composite.resize(_sz + 1);
		do_sieve();	
	}

	int get_prime(size_t n) {
		return prime[n - 1];
	}
};

#endif

linear_sieve sieve(1e7);

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", sieve.get_prime(n));
}
