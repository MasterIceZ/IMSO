/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

struct people_t{
	ll value, size;
	people_t(ll _value, ll _size):
		value(_value), size(_size) {}
};

const int MxN = 5000050;
ll a[MxN], from_left[MxN], from_right[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	stack<people_t> st;
	ll current_size, current_answer = 0ll;
	for(int i=1; i<=n; ++i){
		current_size = 1ll;
		while(!st.empty() && st.top().value >= a[i]){
		    people_t now = st.top(); st.pop();
		    current_answer -= now.value * now.size; // remove this
		    current_size += now.size;
		}
		current_answer += a[i] * current_size;
		from_left[i] = current_answer;
		st.emplace(a[i], current_size);
	}
	while(!st.empty()){
		st.pop();
	}
	current_answer = 0ll;
	for(int i=n; i>=1; --i){
		current_size = 1ll;
		while(!st.empty() && st.top().value >= a[i]){
		    people_t now = st.top(); st.pop();
		    current_answer -= now.value * now.size; // remove this
		    current_size += now.size;
		}
		current_answer += a[i] * current_size;
		from_right[i] = current_answer;
		st.emplace(a[i], current_size);
	}
	ll answer = 0ll;
	for(int i=1; i<=n; ++i){
		answer = max(answer, from_left[i] + from_right[i] - a[i]);
	}
	dbg(to_string(from_left, 1, n));
	dbg(to_string(from_right, 1, n));
	cout << answer;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
