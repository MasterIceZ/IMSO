#include <bits/stdc++.h>
#include "bombs.h"
using namespace std;
using ll = long long;
int cnt = 0, t;
ll ans = 0, sum = 0, s = 0, dis = 0;
priority_queue<ll> l;
priority_queue<ll, vector<ll>, greater<ll>> r;
void initialize(int N) {
    // do nothing
}
ll max_hp_loss(int x, int T, int a, int p) {
    if (++cnt == 1) {
        l.push(x);
        r.push(x);
        sum += a;
        t = T;
        return sum - ans;
    }
    sum += a;
    if (T != t) dis = p * (T - t);
    else dis = 0;
    t = T;
    s += dis;
    ll nowl = l.top() - s;
    ll nowr = r.top() + s;
    if (x < nowl) {
        l.push(x + s);
        l.push(x + s);
        l.pop();
        r.push(nowl - s);
        ans += abs(nowl - x);
    }
    else if (x > nowr) {
        r.push(x - s);
        r.push(x - s);
        r.pop();
        l.push(nowr + s);
        ans += abs(nowr - x);
    }
    else {
        l.push(x + s);
        r.push(x - s);
    }
    return sum - ans;
}
