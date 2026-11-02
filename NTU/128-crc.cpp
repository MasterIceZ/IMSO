#include <algorithm>
#include <iostream>
#include <string>

const long long MOD = 34943;
const char HX[] = "0123456789ABCDEF";

inline long long to_dec(long long x) {
	long long r = 0ll, pw = 1ll;
	for(long long i=0ll; i<8ll; ++i, pw*=2ll, x/=2ll) {
		if(x & 1ll) {
			r += pw;
		}
	}
	return r;
}

inline std::string to_hex(long long x) {
	std::string r = "";
	while(x > 0ll) {
		r += HX[x % 16];
		x /= 16;
	}
	
	while((int) r.size() < 2) {
		r += '0';
	}

	std::reverse(r.begin(), r.end());
	return r;
}

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

	std::string s;
	while(std::getline(std::cin, s)) {
		if(s == "#") {
			break;
		}
		
		long long a = 0ll;
		for(int i=0; i<(int) s.size(); ++i) {
			a = ((a * 256ll) + ((long long) s[i])) % MOD;
		}

		a = (MOD - ((a * 65536ll) % MOD)) % MOD;

		std::string x = to_hex(to_dec(a));
		a = a / 256;
		std::string y = to_hex(to_dec(a));

		std::cout << y << " " << x << "\n";
	}

	return 0;
}
