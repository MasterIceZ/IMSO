#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string seek_next(int t, const std::string &s) {
	std::string r = "";
	for(; t<(int) s.size(); ++t) {
		if(s[t] == '|') {
			break;
		}
		r += std::string(1, s[t]);
	}
	return r;
}

std::string strip(std::string s) {
	while(s.back() == ' ') {
		s.pop_back();
	}
	std::reverse(s.begin(), s.end());
	while(s.back() == ' ') {
		s.pop_back();
	}
	std::reverse(s.begin(), s.end());
	return s;
}

std::string to_key(const std::string &s) {
	char last = ' ';
	std::string lower = "";
	for(auto c: s) {
		if(c == ' ' && last == ' ') {
			continue;
		}
		lower += std::string(1, tolower(c));
		last = c;
	}
	return lower;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::string full_str = "", _;
	std::map<std::string, int> dictionary;
	while(std::getline(std::cin, _)) {
		full_str += _;
	}
	for(int pt=0; pt<(int) full_str.size(); ) {
		if(full_str[pt] == '+' || full_str[pt] == '-' || full_str[pt] == ' ') {
			pt++;
			continue;
		}
		if(full_str[pt] == '|') {
			std::string cur_seek = seek_next(pt + 1, full_str);
			std::string cur_seek_stripped = strip(cur_seek);
			
			if((int) cur_seek_stripped.size() == 0) {
				pt++;
				continue;
			}

			std::string this_key = to_key(cur_seek_stripped);
			dictionary[this_key] += 1;
			
			pt += (int) cur_seek.size() + 1;
		}
	}
	for(auto it: dictionary) {
		std::cerr << "D:" << it.first << " " << it.second << "\n";
	}
	return 0;
}
