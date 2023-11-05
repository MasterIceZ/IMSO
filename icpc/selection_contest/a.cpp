#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e6+5;
const int K=1<<21;

int n,k;
int a[N],l[N],r[N];
queue<int> q[N];
set<int> s;
multiset<int> sl,sr;
ll ans;

struct segtree{
  struct node{
    int val,freq;
    node(int val=0,int freq=1):val(val),freq(freq){}
    friend node operator+(node l,node r){
      if(l.val<r.val)return l;
      if(r.val<l.val)return r;
      return node(l.val,l.freq+r.freq);
    }
  }t[K];
  int lz[K];
  void pushlz(int l,int r,int i){
    t[i].val+=lz[i];
    if(l<r){
      lz[i*2]+=lz[i];
      lz[i*2+1]+=lz[i];
    }
    lz[i]=0;
  }
  void build(int l,int r,int i){
    if(l==r)return void(t[i]=node(0,1));
    int m=(l+r)/2;
    build(l,m,i*2);
    build(m+1,r,i*2+1);
    t[i]=t[i*2]+t[i*2+1];
  }
  void build(){
    build(1,n,1);
  }
  void update(int l,int r,int i,int x,int y,int v){
    pushlz(l,r,i);
    if(y<l||r<x)return;
    if(x<=l&&r<=y)return lz[i]=v,pushlz(l,r,i),void();
    int m=(l+r)/2;
    update(l,m,i*2,x,y,v);
    update(m+1,r,i*2+1,x,y,v);
    t[i]=t[i*2]+t[i*2+1];
  }
  void update(int x,int y,int v){
    update(1,n,1,x,y,v);
  }
}seg;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    q[a[i]].emplace(i);
    s.emplace(a[i]);
  }
  seg.build();
  for(auto x:s){
    q[x].emplace(n+1);
    for(int i=1;i<k;i++)if(!q[x].empty())q[x].pop();
    if(q[x].size()>1){
      l[x]=q[x].front();
      q[x].pop();
      r[x]=q[x].front()-1;
    }
    seg.update(l[x],r[x],1);
  }
  for(int i=1;i<=n;i++){
    if(seg.t[1].val==0)ans+=seg.t[1].freq;
    seg.update(i,i,1e9);
    int x=a[i];
    seg.update(l[x],r[x],-1);
    l[x]=r[x]=0;
    if(q[x].size()>1){
      l[x]=q[x].front();
      q[x].pop();
      r[x]=q[x].front()-1;
      seg.update(l[x],r[x],1);
    }
  }
  cout << ans;
}