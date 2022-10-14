#include "lingling.h"
#include <vector>

using namespace std;

const int MxN = 1010;
int a[MxN], dp[MxN][MxN], ok[MxN][MxN];
bool can[MxN][MxN];

void init_monkeys(std::vector<int> P, int Q){
	int n = P.size();
	for(int i=1; i<=n; ++i){
		a[i] = P[i - 1] + 1;
	}
	for(int i=1; i<=n; ++i){
		for(int j=i + 1; j<=n; ++j){
			dp[i][j] = ok[i][j] = (a[i] > a[j]);
		}
	}
	for(int i=n; i>=1; --i){
		for(int j=1; j<=n; ++j){
			dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	for(int i=1; i<=n; ++i){
		can[i][i] = true;
		for(int j=i+1; j<=n; ++j){
			can[i][j] = (can[i][j - 1] & (a[j] >= i && a[j] <= j));
		}
	}
}

long long minimum_branches(int L, int R){
	L++, R++;
	return (can[L][R] ? dp[L][R]: -1);
}
