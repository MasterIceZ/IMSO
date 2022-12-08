/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: sum primes
 * ALGO		: Binary Search
 * DATE		: 12 Nov 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 5000 * 5 + 10;
bitset<MxN> visited;
vector<int> primes;

inline void solution(){
	int a, b;
	ll cnt = 0ll;
	cin >> a >> b;
	for(int i=a; i<=b; ++i){
		for(int j=i; j<=b; ++j){
			ll cc = upper_bound(primes.begin(), primes.end(), i + j + b) - lower_bound(primes.begin(), primes.end(), i + j + j);
			cnt = cnt + cc;
		}
	}
	cout << cnt;
	return ;
}

inline bool isPrime(int x){
	if(x <= 1){
		return false;
	}
	if(x <= 3){
		return true;
	}
	if(x % 2 == 0 || x % 3 == 0){
		return false;
	}
	for(int i=5; i*i<=x; i+=6){
		if(x % i == 0 || x % (i + 2) == 0){
			return false;
		}
	}
	return true;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	

	for(int i=1; i<=15000; ++i){
		visited[i] = !isPrime(i);
		if(!visited[i]){
			primes.emplace_back(i);
		}
	}

	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
