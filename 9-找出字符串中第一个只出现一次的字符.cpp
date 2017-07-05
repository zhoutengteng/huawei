#include <iostream>
#include <list>
#include <string>
#include <cstring>
using namespace std;

int main() {
	string str;
	while (getline(cin , str)) {
		char map[128];
		list<char> li;
		memset(map, 2, sizeof(char)*128); 
		for (int i = 0; i < str.length(); i++) {
			if (map[str[i]] == 2) {
				map[str[i]] -= 1;
				li.push_back(str[i]);
			} else if (map[str[i]] == 1) {
				list<char>::iterator itli;
				for (itli = li.begin(); itli != li.end(); itli++) {
					if (*itli == str[i]) {
						li.erase(itli);
						break;
					}
				}
				map[str[i]] -= 1;
			}
		}
		if (li.empty()) {
			cout <<  '.' << std::endl;
		} else {
			cout << li.front() << endl;
		}
	}
}