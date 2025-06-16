#include "egg.h"
#include <cmath>

int find_level(int N) {
  int sq = sqrt(N);
  int cluster_no = 1;
  for(int i=sq; i<=N; i+=sq){
    bool res = throw_egg(i);
    if(res == true) {
      cluster_no = i;
      break;
    }
  }
  for(int i=cluster_no - sq + 1; i<=cluster_no; ++i){
  	if(throw_egg(i) == true){
		return i;
	}
  }
}
