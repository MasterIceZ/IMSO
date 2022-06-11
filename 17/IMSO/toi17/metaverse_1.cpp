/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: metaverse
 * ALGO		: Dynamic Programming
 * DATE		: 29 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Warp{
	int a, b, c, d;
};

const int MxN = 20020;
const int MxS = 22;

Warp warp[MxN];
int dp[MxN][MxS];

int calc(int a, int b, int c, int d){
	return abs(a - c) + abs(b - d);
}

int main(){
	int n, m, k, p, a, b, c, d;
	scanf("%d %d %d %d", &n, &m, &k, &p);
	for(int i=1; i<=k; ++i){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		warp[i] = Warp{a, b, c, d};
	}
	memset(dp, 0x3f, sizeof dp);
	for(int i=1; i<=k; ++i){
		dp[i][1] = calc(1, 1, warp[i].a, warp[i].b);
	}
	for(int state=2; state<=p; ++state){
		for(int i=1; i<=k; ++i){
			for(int j=1; j<=k; ++j){
				if(i == j){
					continue;
				}
				dp[i][state] = min(dp[i][state], dp[j][state - 1] + calc(warp[i].a, warp[i].b, warp[j].c, warp[j].d));
			}
		}
	}
	int answer = calc(1, 1, n, m), count = 0;
	for(int state=1; state<=p; ++state){
		for(int i=1; i<=k; ++i){
			int current = dp[i][state] + calc(warp[i].c, warp[i].d, n, m);
			if(current < answer){
				answer = current;
				count = state;
			}
		}
	}
	printf("%d %d\n", answer, count);
	return 0;
}
