struct Square_root_Decompostion{
	size_t n, sq;
	vector<int> cluster, dp;
	Square_root_Decomposition(size_t N){
		n = N;
		sq = sqrt(n);
		cluster.resize(sq + 2, 0);
		dp.resize(n + 2, 0);
	}
	Square_root_Decomposition(vector<int> a){
		dp = a;
		sq = sqrt(n);
		cluster.resize(sq + 2, 0);
		for(int i=1; i<=n; ++i){
			cluster[i / sq] += a[i];
		}
	}
	void update(int idx, int v){
		dp[idx] = v;
		cluster[idx / sq] = 0;
		for(int i=(idx / sq) * sq; i<min((idx / sq) * sq * + sq, n); ++i){
			cluster[idx /sq] += dp[i];
		}
	}
	int read(){
	
	
	}
};
