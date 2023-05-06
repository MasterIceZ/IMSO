#include <bits/stdc++.h>
#include "bombs.h"

using namespace std;
using ll = long long;

ll last_time = 0ll;

struct slope_trick{
	multiset<ll> ms_l, ms_r;
	ll max_y = 0ll, lzy_l = 0ll, lzy_r = 0ll;
	bool state = false;
	inline void add_line(ll value, ll current_time, ll speed, ll damage){
		max_y += damage;
		// extend slope
		ll move_steps = (current_time - last_time) * speed;
		if(state){
			lzy_l -= move_steps;
			lzy_r += move_steps;
		}
		state = true;
		// real_value = lazy + in_value
		// in_value = real_value - lazy
		if(ms_l.empty() && ms_r.empty()){
			ms_l.emplace(value);
			ms_r.emplace(value);
		}
		else if(value <= *ms_l.rbegin() + lzy_l){
			max_y -= (*ms_l.rbegin() + lzy_l) - value;
			ms_r.emplace(*ms_l.rbegin() + lzy_l - lzy_r);
			ms_l.erase(--ms_l.end());
			ms_l.emplace(value - lzy_l);
			ms_l.emplace(value - lzy_l);
		}
		else if(value >= *ms_r.begin() + lzy_r){
			max_y -= value - (*ms_r.begin() + lzy_r);
			ms_l.emplace(*ms_r.begin() + lzy_r - lzy_l);
			ms_r.erase(ms_r.begin());
			ms_r.emplace(value - lzy_r);
			ms_r.emplace(value - lzy_r);
		}
		else{
			ms_l.emplace(value - lzy_l);
			ms_r.emplace(value - lzy_r);
		}
		return ;
	}
} dp;

// Concave function
// find max_y (PEAK)

// f[i](x) = maximum of HP loss with no move while computing `i`; current posistion -> x
// g[i](x) = maximum of HP loss with moving while computing `i`; current position -> x
// extend f[i](x) to g[i](x) with move_steps

// l[i](x) = damage - |value - x|
// f[i](x) = l[i](x) + max(f[i - 1](k)); x - move_steps <= k <= x + move_steps
// g[x](x) = max(f[i](k)); x - move_steps <= k <= x + move_steps
// f[i](x) = l[i](x) + g[i - 1](x)

void initialize(int N) {
	return;
}

long long max_hp_loss(int X, int T, int A, int P) { 
	dp.add_line(X, T, P, A);
	last_time = T;
	return dp.max_y;
}
