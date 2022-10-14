#include "2eggs.h"
#include <cmath>

int height_threshold(int N, int Q) {
  int sq = sqrt(N);
  int cluster_no = 1;
  for(int i=sq; i<=N; i+=sq){
	  bool res = drop_egg(1, i);
	  if(res == true){
		  cluster_no = i;
		  break;
	  }
  }
  for(int i=cluster_no - sq + 1; i<=cluster_no; ++i){
  	if(drop_egg(2, i) == true){
		return i;
	}
  }
}
