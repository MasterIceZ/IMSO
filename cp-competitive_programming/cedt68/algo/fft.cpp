#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

const int MxN = 100010;

double fac[MxN];

void fft(std::vector<std::complex<double>> &a, bool inv) {
	int n = a.size();
	for(int i=1, j=0; i<n; ++i) {
		int b = n >> 1;
		for(; j & b; b >>= 1) {
			j ^= b;
		}
		j ^= b;
		if(i < j) {
			std::swap(a[i], a[j]);
		}
	}

	for(int len=2; len<=n; len<<=1) {
		double angle = 2 * acos(-1) / len * (inv ? -1 : 1);
		std::complex<double> wlen(cos(angle), sin(angle));
		for(int i=0; i<n; i+=len) {
			std::complex<double> w(1);
			for(int j=0; j<len/2; ++j) {
				std::complex<double> u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if(inv) {
		for(auto &x: a) {
			x /= n;
		}
	}
}

std::vector<double> convolute(const std::vector<double> &a, const std::vector<double> &b) {
	int n = 1;
	while(n < (int) a.size() + (int) b.size()) {
		n <<= 1;
	}

	std::vector<std::complex<double>> freq_a(a.begin(), a.end());
	std::vector<std::complex<double>> freq_b(b.begin(), b.end());
	freq_a.resize(n);
	freq_b.resize(n);

	fft(freq_a, false);
	fft(freq_b, false);
	for(int i=0; i<n; ++i) {
		freq_a[i] *= freq_b[i];
	}
	fft(freq_a, true);

	int res_sz = (int) a.size() + (int) b.size() + 1;
	std::vector<double> res_poly(res_sz);
	for(int i=0; i<res_sz; ++i) {
		res_poly[i] = freq_a[i].real();
	}
	return res_poly;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

	fac[0] = 1;
	for(int i=1; i<MxN; ++i) {
		fac[i] = fac[i - 1] * i;
	}

	int n, p[4];
	std::cin >> n >> p[0] >> p[1] >> p[2] >> p[3];
	
	std::vector<double> poly = {1.0};
	for(int i=0; i<4; ++i) {
		std::vector<double> term;
		for(int j=0; j<=p[i]; ++j) {
			term.emplace_back(1.0 / fac[j]);
		}
		poly = convolute(poly, term);
		if((int) poly.size() > n + 1) {
			poly.resize(n + 1);
		}
	}
	long long answer;
	if(n >= (int) poly.size()) {
		answer = 0ll;
	}
	else {
		double t = poly[n] * fac[n];
		answer = (long long) (t + 0.5);
	}

	std::cout << answer << "\n";

	return 0;
}
