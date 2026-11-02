#include <iostream>
#include <map>
#include <queue>


int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	
	bool good = true;
	std::map<std::string, std::string> adj;
	std::string s;

	while(std::cin >> s) {
		if(s == "()") {
			if(good == false) {
				std::cout << "not complete\n";
				good = true;	
				adj.clear();
				continue;
			}

			std::queue<std::string> q;
			std::vector<std::string> gone;
			if(adj.count("")) {
				q.emplace("");
				gone.emplace_back(adj[""]);
				adj.erase("");
			}
			while(!q.empty()) {
				std::string cur = q.front();
				q.pop();
				for(auto to_add: "LR") {
					std::string new_cur = cur + to_add;
					if(adj.count(new_cur)) {
						q.emplace(new_cur);
						gone.emplace_back(adj[new_cur]);
						adj.erase(new_cur);
					}
				}
			}

			if(adj.empty()) {
				for(int i=0; i<(int) gone.size(); ++i) {
					std::cout << gone[i] << " \n"[i == (int) gone.size() - 1];
				}
			}
			else {
				std::cout << "not complete\n";
			}

			adj.clear();
			continue;
		}

		int seek_ptr = 1;
		std::string a = "", b = "";
		while(s[seek_ptr] != ',') {
			a += s[seek_ptr++];
		}
		seek_ptr++;
		while(s[seek_ptr] != ')') {
			b += s[seek_ptr++];
		}
		if(adj.count(b)) {
			good = false;
		}
		else {
			adj[b] = a;
		}
	}

	return 0;
}
