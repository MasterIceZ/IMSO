/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: bstpractice
 * ALGO		: Binary Search Tree
 * DATE		: 5 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;
int a[MxN], l[MxN], r[MxN];

void solve(int id){
	cin >> a[id];
	if(id == 1){
		cout << "*";
		return ;
	}
	int it = 1;
	while(1){
		if(a[id] < a[it]){
			cout << "L";
			if(!l[it]){
				l[it] = id;
				break;
			}
			it = l[it];
		}
		else if(a[id] > a[it]){
			cout << "R";
			if(!r[it]){
				r[it] = id;
				break;
			}
			it = r[it];
		}
	}
	cout << "*";
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1, id=1;
	cin >> q;
	while(q--){
		solve(id++);
		cout << "\n";
	}
	return 0;
}
