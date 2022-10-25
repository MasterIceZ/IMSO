#include "coin.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;
vector<int> rail;
Node tree[MxN];
int N, rail[MxN];

void initialize(int N,std::vector<int> Rail,int L)
{
	N = Rail.size();
	for(int i=1; i<=N; ++i){
		rail[i] = Rail[i - 1];
	}
	build(1, N, 1);
    return;
}

int calc(vector<int> v){
}

std::vector<int> max_dist(std::vector<std::vector<int> > Coins)
{
    std::vector<int> Ans;
	for(auto coin: Coins){
		Ans.emplace_back(calc(coin));
	}
    return Ans;
}
