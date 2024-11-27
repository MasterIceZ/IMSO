#include "moodeng.h"
#include<bits/stdc++.h>
using namespace std;
 
void search(int N, int M, int T) {
  //Init
  hash<string> hs;
  srand(hs("Moodeng real")); // hoping that some value gets 100pts
  const int N_CRIT=25;
  const int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
 
  vector<vector<bool>> q(N,vector<bool>(M,false));
  vector<pair<int,int>> coord1,coord2; //coord1 is true, coord2 is false in space of possible squares
   
  //First query
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if((i+j)%2==0){
        q[i][j]=true;
        coord1.push_back({i,j});
      }
      else{
        coord2.push_back({i,j});
      }
    }
  }
 
  //Loop
  while(true){
    set<pair<int,int>> nextq;
    vector<pair<int,int>> nextqvec;
    fprintf(stderr,"%d\n",(int)coord1.size());
    int maxx=-1,maxy=-1,minx=5000,miny=5000;
    if(query(q)){ //moodeng was in coord1
      for(auto [x,y]:coord1){
        for(int i=0;i<4;i++){
          if(x+dx[i]<0||x+dx[i]>=N||y+dy[i]<0||y+dy[i]>=M){continue;}
 
          if(nextq.find({x+dx[i],y+dy[i]})==nextq.end()){
            nextq.insert({x+dx[i],y+dy[i]});
            nextqvec.push_back({x+dx[i],y+dy[i]});
            maxx=max(maxx,x+dx[i]);minx=min(minx,x+dx[i]);
            maxy=max(maxy,y+dy[i]);miny=min(miny,y+dy[i]);
          }
        }
      }
    }
    else{ //moodeng was in coord2
      for(auto [x,y]:coord2){
        for(int i=0;i<4;i++){
          if(x+dx[i]<0||x+dx[i]>=N||y+dy[i]<0||y+dy[i]>=M){continue;}
 
          if(nextq.find({x+dx[i],y+dy[i]})==nextq.end()){
            nextq.insert({x+dx[i],y+dy[i]});
            nextqvec.push_back({x+dx[i],y+dy[i]});
            maxx=max(maxx,x+dx[i]);minx=min(minx,x+dx[i]);
            maxy=max(maxy,y+dy[i]);miny=min(miny,y+dy[i]);
          }
        }
      }
    }
 
    fprintf(stderr,"ckpt1\n");
    coord1.clear();
    coord2.clear();
    q=vector<vector<bool>>(N,vector<bool>(M,false));
 
    fprintf(stderr,"ckpt2\n");
    if(nextqvec.size()<=N_CRIT){ // Make a guess!
      pair<int,int> copium=nextqvec[rand()%nextqvec.size()]; // COPE PLEASE
      fprintf(stderr,"ckpt3\n");
      q[copium.first][copium.second]=true;
      coord2=nextqvec;
      coord2.erase(find(coord2.begin(),coord2.end(),copium));
    }
    else{ //Slice in half
      if(maxx-minx>maxy-miny){
        sort(nextqvec.begin(),nextqvec.end(), [](pair<int,int> a, pair<int,int> b){
            if(a.first==b.first){
              return a.second>b.second;
            }
            return a.first>b.first;
            });
      }
      else{
        sort(nextqvec.begin(),nextqvec.end(), [](pair<int,int> a, pair<int,int> b){
            if(a.second==b.second){
              return a.first>b.first;
            }
            return a.second>b.second;
            });
      }
      for(int i=0;i<nextqvec.size()/2;i++){
        auto [x,y]=nextqvec[i];
        coord1.push_back({x,y});
        q[x][y]=true;
      }
      for(int i=nextqvec.size()/2;i<nextqvec.size();i++){
        coord2.push_back(nextqvec[i]);
      }
    }
  }
}