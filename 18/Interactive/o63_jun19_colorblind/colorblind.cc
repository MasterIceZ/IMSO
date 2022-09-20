/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o63_jun19_colorblind
 * ALGO		: Interavtive
 * DATE		: 20 Sep 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

#include "colorblind.h"

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

std::string investivate_colors(int N) {
//	if(N == 1){
//		return "RB";
//	}
//	if(N == 2){
//		if(use_device(0, 1) == 4){
//			return "RRBB";
//		}
//		if(use_device(1, 2) == 4){
//			return "RBRB";
//		}
//		return "RBBR";
//	}
	string res = "";
	for(int i=1; i<=N; ++i){
		res = res + "R";
	}
	for(int i=1; i<=N; ++i){
		res = res + "B";
	}
	return res;
}
