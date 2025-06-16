#include "grader.h"
#include "cluedo.h"

void Solve(){
   int r;
   r = Theory(1,2,3);
   if (r == 0) return;
   r = Theory(3,2,1);
   if (r == 0) return;
   r = Theory(4,4,4);
   if (r == 0) return;
}
