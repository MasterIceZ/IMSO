struct euler_totient {
	size_t n;
	int *phi;
	
	int phi(int n) {
		return phi[n];
	}

	void calculate_phi(int n) {
		for(int i=2; i<=n; ++i) {
			if(phi[i] != i) {
				continue;
			}
			for(int j=i; j<=n; j+=i) {
				phi[j] -= phi[j] / i;
			}
			phi[i] = i - 1;
		}
	}

	euler_totient (size_t _n): n(_n + 10) {
		phi = (int *) calloc(n, sizeof (int));
		for(int i=1; i<n; ++i) {
			phi[i] = i;
		}
		calculate_phi(n);
	}
};
