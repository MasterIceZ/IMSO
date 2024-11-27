#include"holiday.h"
#include <bits/stdc++.h>
using namespace std;
int* attraction;
int start;
int n,d;
vector<pair<int,int> > vatr;
long long pseg[8000005];
int cseg[8000005];
int lb[8000005];
int rb[8000005];
int llink[8000005];
int rlink[8000005];
int nodesz;
int newnode(int old = -1){
	int nn = ++nodesz;
	if(old != -1){
		pseg[nn] = pseg[old];
		cseg[nn] = cseg[old];
		lb[nn] = lb[old];
		rb[nn] = rb[old];
		llink[nn] = llink[old];
		rlink[nn] = rlink[old];
	}
	return nn;
}
int build(int l, int r){
	int c = newnode();
	pseg[c] = 0;
	cseg[c] = 0;
	lb[c] = l;
	rb[c] = r;
	if(l == r) return c;
	int k = (l+r)/2;
	llink[c] = build(l, k);
	rlink[c] = build(k+1, r);
	return c;
}
int update(int o, int idx){
	int c = newnode(o);
	if(lb[o] == rb[o]){
		cseg[c] = 1;
		pseg[c] = vatr[idx].first;
		return c;
	}
	int k = (lb[o] + rb[o])/2;
	if(idx <= k){
		llink[c] = update(llink[c], idx);
	}else{
		rlink[c] = update(rlink[c], idx);
	}
	pseg[c] = pseg[llink[c]] + pseg[rlink[c]];
	cseg[c] = cseg[llink[c]] + cseg[rlink[c]];
	return c;
}
long long query(int n1, int n2, int lim){
	int avail = cseg[n2] - cseg[n1];
	if(avail <= lim) return pseg[n2] - pseg[n1];
	int rsz = cseg[rlink[n2]] - cseg[rlink[n1]];
	if(rsz < lim){
		return query(llink[n1], llink[n2], lim - rsz) + pseg[rlink[n2]] - pseg[rlink[n1]];
	}else{
		return query(rlink[n1], rlink[n2], lim);
	}
}
vector<int> versions;
long long computeManyMax(int k, int l, int r){
	long long res = query(versions[l], versions[r+1], k);
	return res;
}
long long divideConquer(int l, int r, int ll, int rr){
	if(l > r) return 0ll;
	int m = (l+r)/2;
	long long ans = 0;
	int rmidx = -1;
	int lmidx = -1;
  cerr << "T: " << ll << " " << rr << "\n";
	for(int i = ll; i <= rr; i++){
		int dist = m-i+min(start-i,m-start);
		if(dist > d) continue;
    cerr << "X: " << l << " " << r << " " << dist << "\n";
		long long cur = computeManyMax(d - dist, i, m);
		if(cur > ans){
			ans = cur;
			lmidx = rmidx = i;
		}else if(cur == ans){
			rmidx = i;
		}
	}
	ans = max(ans, divideConquer(l, m-1, ll, rmidx));
	ans = max(ans, divideConquer(m+1, r, lmidx, rr));
	return ans;
}
long long int findMaxAttraction(int n, int start, int d, int attraction[]) {
	::attraction = attraction;
	::start = start;
	::n = n;
	::d = d;
	for(int i = 0; i < n; i++) vatr.emplace_back(attraction[i], i);
	sort(vatr.begin(), vatr.end());
	int root = build(0, n-1);
	versions.push_back(root);
	for(int i = 0; i < n; i++){
		int idx = lower_bound(vatr.begin(), vatr.end(), make_pair(attraction[i], i)) - vatr.begin();
		int newroot = update(root, idx);
		versions.push_back(newroot);
		root = newroot;
	}
	return divideConquer(start, n-1, 0, start);
}