#include<bits/stdc++.h>

using namespace std;

const double C = sqrt(2.0);

struct Info{
  int val,cnt;
  Info(int _val,int _cnt):val(_val),cnt(_cnt){}
  friend Info operator+(const Info &a,const Info &b){
    if(a.val<b.val){
      return a;
    }
    if(b.val<a.val){
      return b;
    }
    return Info(a.val,a.cnt+b.cnt);
  }
};

struct SegTree{
  struct Node;
  using Ptr = Node*;
  struct Node{
    Info val;
    int lz;
    Ptr l,r;
    Node(Info x):val(x),lz(0),l(),r(){}
  };
  Info make(int l,int r){
    return Info(0,r-l+1);
  }
  int n;
  Ptr root;
  SegTree(int _n):n(_n),root(new Node(make(0,n-1))){}
  void apply(int l,int r,Ptr &t,int v){
    if(!t)t=new Node(make(l,r));
    t->val.val+=v;
    t->lz+=v;
  }
  void push(int l,int m,int r,Ptr t){
    apply(l,m,t->l,t->lz);
    apply(m+1,r,t->r,t->lz);
    t->lz=0;
  }
  void update(int l,int r,Ptr &t,int x,int y,int v){
    if(y<l||r<x)return;
    if(x<=l&&r<=y)return apply(l,r,t,v);
    int m=(l+r)/2;
    push(l,m,r,t);
    update(l,m,t->l,x,y,v);
    update(m+1,r,t->r,x,y,v);
    t->val=t->l->val+t->r->val;
  }
  void update(int x,int y,int v){
    update(0,n-1,root,x,y,v);
  }
};

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,w;
  cin >> n >> w;
  SegTree seg(w);
  map<pair<int,int>,bool> seen;
  cout << fixed << setprecision(15);
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    if(seen[{x,y}]){
      seg.update(x-y,x+y-1,-1);
    }else{
      seg.update(x-y,x+y-1,+1);
    }
    seen[{x,y}]^=true;
    auto res=seg.root->val;
    int ans=w;
    if(res.val==0){
      ans-=res.cnt;
    }
    cout << ans*C << "\n";
  }
}