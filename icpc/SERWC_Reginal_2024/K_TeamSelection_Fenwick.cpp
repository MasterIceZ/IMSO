#include <bits/stdc++.h>

using namespace std;

template<class T>
struct fenwick{
    int n;
    vector<T> t;
    fenwick(int n=0){init(n);}
    void init(int _n){
        n=_n;
        t.assign(n+1,T{});
    }
    void update(int x,const T &v){
        for(int i=x+1;i<=n;i+=i&-i)t[i]=t[i]+v;
    }
    void update(int l,int r,const T &v){
        update(l,v),update(r+1,-v);
    }
    T query(int x){
        T res{};
        for(int i=x+1;i>0;i-=i&-i)res=res+t[i];
        return res;
    }
    T query(int l,int r){
        return query(r)-query(l-1);
    }
    int find(const T &k){
        int x=0;
        T cur{};
        for(int i=1<<31-__builtin_clz(n);i>0;i>>=1)
            if(x+i<=n&&cur+t[x+i]<k)x+=i,cur=cur+t[x];
        return x;
    }
};

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	fenwick<int> fw(n);
	for(int i=0; i<n; ++i) {
		fw.update(i, 1);
	}
	n /= 2;
	vector<int> a(n), b(n);
	for(auto &x: a) {
		cin >> x;
	}
	for(auto &x: b) {
		cin >> x;
	}
	for(int i=0; i<n; ++i) {
		a[i] = fw.find(a[i]);
		fw.update(a[i], -1);
		b[i] = fw.find(b[i]);
		fw.update(b[i], -1);
	}
	for(auto x: a) {
		cout << 1 + x << " ";
	}
	cout << "\n";
	for(auto x: b) {
		cout << 1 + x << " ";
	}
	cout << "\n";
}
