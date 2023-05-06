/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: TYPE PRINTER
 * ALGO		: Trie
 * DATE		: 3 May 2023
 * */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

struct node_t{
	int cnt = 0;
	bool done;
	//node_t *nxt[26];
	map<int, node_t*> nxt;

	node_t(){
		cnt = 0;
		done = false;
	//	for(int i=0; i<26; ++i){
	//		nxt[i] = NULL;
	//	}
	}
};

struct trie_t{
	node_t root;
	void insert(string s){
		node_t *cur = &root;
		for(int i=0; i<(int)s.size(); ++i){
			if(cur->nxt.find(s[i] - 'a') == cur->nxt.end()){
				cur->nxt[s[i] - 'a'] = new node_t();
			}
			cur = cur->nxt[s[i] - 'a'];
		}
		cur->cnt++;
	}
	void check(string s){
		node_t *cur = &root;
		for(int i=0; i<(int)s.size(); ++i){
			cur = cur->nxt[s[i] - 'a'];
			cur->done = true;
		}
	}
} t;

string answer_string = "";

int dfs(node_t *u){
	int res = u->cnt;
	for(int i=0; i<res; ++i){
		answer_string += "P\n";
	}
	for(int i=0; i<26; ++i){
		if(u->nxt.find(i) != u->nxt.end() && u->nxt[i]->done == false){
			answer_string += ((char) (i + 'a'));
			answer_string += "\n";
			res += dfs(u->nxt[i]);
			answer_string += "-\n";
			res += 2;
		}
	}
	for(int i=0; i<26; ++i){
		if(u->nxt.find(i) != u->nxt.end() && u->nxt[i]->done == true){
			answer_string += ((char) (i + 'a'));
			answer_string += "\n";
			res += dfs(u->nxt[i]);
			res += 1;
		}
	}
	return res;
}

inline void solution(){
	int n;
	string s, l = "";
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> s;
		t.insert(s);
		if(s.size() > l.size()){
			l = s;
		}
	}	
	t.check(l);
	cout << dfs(&t.root) << "\n" << answer_string;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
