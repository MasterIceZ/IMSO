#include <vector>
#include <algorithm>
 
long long x[10], y[10];
long long mincost_color(int C, std::vector<int> xs, std::vector<int> ys)
{
    for(int i=0;i<3*C;i++){x[i] = xs[i]; y[i]=ys[i];}
    return std::abs(x[0]*y[1] - x[1]*y[0] + x[1]*y[2] - x[2]*y[1] + x[2]*y[0] - x[0]*y[2]);
}