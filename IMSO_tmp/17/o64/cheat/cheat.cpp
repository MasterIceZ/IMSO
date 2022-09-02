#include<bits/stdc++.h>
using namespace std;

#include "cheat.h"

const int MxN = 200020;

pair<int, int> p[MxN];
int sz[MxN], t = 0;
bool started = false;

void init(){
	started = true;
	for(int i=1; i<=200000; ++i){
		p[i] = make_pair(i, 0);
		sz[i] = 1;
	}
}

inline int fr(int u){
	while(u != p[u].first){
		u = p[u].first;
	}
	return u;
}

inline int fr2(int u, int mid){
	while(p[u].second != 0 && p[u].second <= mid){
		u = p[u].first;
	}
	return u;
}

void cheat(int person1, int person2)
{
    if(!started){
		init();
	}
	++t;
	int pu = fr(person1);
	int pv = fr(person2);
	if(pu == pv){
		return ;
	}
	if(sz[pu] > sz[pv]){
		swap(pu, pv);
	}
	p[pu] = make_pair(pv, t);
	sz[pv] += sz[pu];
}

int investigate(int person1, int person2)
{
	if(!started){
		init();
	}
	int l = 0, r = t + 1;
	while(l < r){
		int mid = (l + r) >> 1;
		int pu = fr2(person1, mid);
		int pv = fr2(person2, mid);
		if(pu != pv){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
    return l == t + 1 ? -1: l;
}

#ifdef _DEBUG
#include "cheat.h"

static int N, Q;

int main()
{
  char buf[10];
  
  scanf("%d %d",&N,&Q);
  for(int i=0; i<N+Q; i++) {
    int p1,p2;
    scanf("%s %d %d",buf,&p1,&p2);
    if(buf[0] == 'c')
      cheat(p1,p2);
    else
      printf("%d\n",investigate(p1,p2));
  }
}

#endif
