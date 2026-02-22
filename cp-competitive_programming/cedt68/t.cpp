#include <iostream>

struct event_t {
	int t, type, id;

	event_t(int _t, int _type, int _id) :
		t(_t), type(_type), id(_id) {}

	bool operator < (const event_t& o) const {
		if(t != o.t) {
			return t < o.t;
		}
		if(type != o.type) {
			return type < o.type;
		}
		return id < o.id;
	}
};

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, k;
	std::cin >> n >> k;
	std::vector<event_t> event_points;
	for(int i=1; i<=n; ++i) {
		int l, r;
		std::cin >> l >> r;
		event_points.emplace_back(l, 2, i);
		event_points.emplace_back(r, 1, i);
	}
	int q;
	std::cin >> q;
	for(int i=0; i<q; ++i) {
		int x;
		std::cin >> x;
		event_points.emplace_back(x, 3, i);
	}
	std::vector<bool> answer(q);
	std::sort(event_points.begin(), event_points.end());
	int current_sum = 0;
	for(auto e: event_points) {
		if(e.t == 1) {
			current_sum -= 1;
		}
		else if(e.t == 2) {
			current_sum += 1;
		}
		else {
			answer[e.id] = (current_sum >= k);
		}
	}

	for(auto a: answer) {
		std::cout << (a ? "YES" : "NO") << "\n";
	}
	return 0;
}
