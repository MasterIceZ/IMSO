#include "wirelib.h"

int sol[1000];

main()
{
  int m = wire_init();

  for(int i=0; i<m; i++)
    sol[i+1] = i+1;
  
  for(int i=0; i<m; i++) {
    cmd_C(i+1);
    if(cmd_T(i+1)) {
      sol[i+1] = i+1;
    }
    cmd_C(i+1);
  }
  cmd_D(sol);
}
