#include <iostream>
#include <string>
#include <vector>

long long cnt;
std::string s;

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	long long n;
	std::cin >> n >> s;
	s = " " + s;
	std::vector<long long> cnt_ones(s.size(), 0ll);
	for(long long i=1; i<=n; ++i) {
		cnt_ones[i] = cnt_ones[i-1] + (s[i] == '1');
	}
	for(long long sz=2ll; sz<=2ll*n; sz *= 2ll) {
		long long h = sz / 2;
		for(long long l=1ll; l+h-1ll<=n; l+=sz) {
			long long  mid = l + h;
			long long r = std::min(l + sz - 1ll, n);
			long long l_ones = cnt_ones[mid-1] - cnt_ones[l-1];
			long long r_ones = cnt_ones[r] - cnt_ones[mid-1];
			if(l_ones == 0) {
				cnt += r -  mid + 1ll;
			}
			else {
				cnt += (r_ones == 0ll ? l_ones : r_ones);
			}
		}
	}
	std::cout << cnt << "\n";
	return 0;
}
