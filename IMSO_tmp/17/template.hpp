#include <vector>
#include <string>
#include <cstring>
using namespace std;

template<class T> vector<T> to_vector(T a[], int l, int r){
	vector<T> v;
	for(int i=l; i<=r; ++i){
		v.push_back(a[i]);
	}
	return v;
}

string to_string(string s){
	return s;
}

string to_string(char s){
	return string(1, s);
}

string to_string(const char* s){
	return string(s);
}

template<class T> string to_string(T v){
	bool f = 1;
	string res;
	for(auto x: v){
		if(!f){
			res += ' ';
		}
		f=0;
		res += to_string(x);
	}
	return res;
}

void DBG(){
	cerr << "]" << "\n";
}

template<class H, class... T> void DBG(H h, T... t){
	cerr << to_string(h);
	if(sizeof...(t)){
		cerr << ", ";
	}
	DBG(t...);
}

#ifdef _DEBUG
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
