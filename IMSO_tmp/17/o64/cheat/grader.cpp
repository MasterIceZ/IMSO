#include "cheat.h"
#include <cstdio>

static int N, Q;

int main()
{
  char buf[10];
  
  scanf("%d %d",&N,&Q);
  for(int i=0; i<N+Q; i++) {
    int p1,p2;
    scanf("%s %d %d",buf,&p1,&p2);
    if(buf[0] == 'C')
      cheat(p1,p2);
    else
      printf("%d\n",investigate(p1,p2));
  }
}

