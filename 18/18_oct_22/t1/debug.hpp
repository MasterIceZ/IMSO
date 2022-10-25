/*
 * Written by [Hydrolyzed](https://github.com/MasterIceZ)
 * */


// Header Guard
#ifndef ___SELF_DEBUG_TEMPLATE___
#define ___SELF_DEBUG_TEMPLATE___

// Include
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

namespace UTILS{
	template<class T> vector<T> to_vector(T a[], size_t l, size_t r){
		vector<T> vt;
		 for(size_t i=l; i<=r; ++i){
			 vt.push_back(a[i]);
		 }
		 return vt;
	}
	template<size_t S> vector<bool> to_vector(bitset<S> bs, size_t l, size_t r){
		vector<bool> vt;
		for(size_t i=l; i<=r; ++i){
			vt.push_back(bs[i]);
		}
		return vt;
	}
}

string to_string(bool x){
	return x ? "TRUE": "FALSE";
}

string to_string(char s){
	return string(1, s);
}

string to_string(string s){
	return s;
}

string to_string(const char* s){
	return string(s);
}

template<class T> string to_string(vector<T> vt, string sep=", "){
	bool ok = false;
	string res = "(";
	for(auto x: vt){
		if(ok){
			res += sep;
		}
		ok = true;
		res += to_string(x);
	}
	return res + ")";
}

template<size_t S> string to_string(bitset<S> bs, size_t l, size_t r, string sep=", "){
	vector<bool> vt = UTILS::to_vector(bs, l, r);
	return to_string(vt, sep);
}

template<class T, class S> string to_string(pair<T, S> p){
	string res = "(";
	res += to_string(p.first);
	res += ", ";
	res += to_string(p.second);
	res += ")";
	return res;
}

template<class T> string to_string(T a[], size_t l, size_t r, string sep=", "){
	vector<T> vt = UTILS::to_vector(a, l, r);
	return to_string(vt, sep);
}

template<class T> string to_string(stack<T> st, string sep=", "){
	vector<T> vt;
	while(!st.empty()){
		vt.emplace_back((T)st.top());
		st.pop();
	}
	return to_string(vt, sep);
}

template<class T> string to_string(queue<T> q, string sep=", "){
	vector<T> vt;
	while(!q.empty()){
		vt.emplace_back((T)q.front());
		q.pop();
	}
	return to_string(vt, sep);
}

template<class T> string to_string(priority_queue<T> pq, string sep=", "){
	vector<T> vt;
	while(!pq.empty()){
		vt.emplace_back((T)pq.top());
		pq.pop();
	}
	return to_string(vt, sep);
}

void DBG(){
	cerr << "]\n";
}

template<class H, class... T> void DBG(H h, T... t){
	cerr << to_string(h);
	if(sizeof...(t)){
		cerr << ", ";
	}
	DBG(t...);
}

#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

#endif
