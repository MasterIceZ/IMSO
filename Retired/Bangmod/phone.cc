#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct State{
    int i, j, w;
    State(int _i, int _j, int _w):
        i(_i), j(_j), w(_w) {}
};

const int MxN = 1010;
int a[MxN][MxN];

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    queue<State> q;
    for(int i=1; i<=k; ++i){
        int s, t, w;
        cin >> s >> t >> w;
        //s += 1; t += 1;
        q.emplace(s, t, w);
        a[s][t] = w;
        cerr << "D: " << s << " " << t << "\n";
    }
    cerr << "BEFORE\n";
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cerr << a[i][j] << " " ;
        }
        cerr << "\n";
    }
    while(!q.empty()){
        State now = q.front(); q.pop();
        if(a[now.i][now.j] != now.w){
            continue;
        }
        if(now.w == 1){
            continue;
        }
        for(int k=0; k<4; ++k){
            int ii = di[k] + now.i;
            int jj = dj[k] + now.j;
            if(ii < 1 || jj < 1 || ii > n || jj > m){
                continue;
            }
            if(a[ii][jj] < now.w - 1){
                a[ii][jj] = now.w - 1;
                q.emplace(ii, jj, now.w - 1);
            }
        }
    }
    cerr << "AFTER\n";
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cerr << a[i][j] << " " ;
        }
        cerr << "\n";
    }
    int r;
    cin >> r;
    while(r--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(a[x1][y1] && a[x2][y2]){
            cout << "Y " << a[x1][y1] << " " << a[x2][y2];
        }
        else{
            cout << "N";
        }
        cout << "\n";
    }
    return 0;
}


