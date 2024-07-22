int splitter(int n, int m) {
	if(n == 0 || m == 0) {
		return 0;
	}
	if(n % 2 == 0 && m % 2 == 0) {
		return splitter(n / 2, m / 2);
	}
	if((n % 2 == 1 || m % 2 == 1) && (n + m) % 2 == 1) {
		if(n % 2 == 1) {
			return m + splitter(n / 2, m / 2);
		}
		else {
			return n + splitter(n / 2, m / 2);
		}
	}
	return n + m - 1 + splitter(n / 2, m / 2);
}
