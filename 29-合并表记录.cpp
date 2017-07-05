#include <iostream>
#include <memory.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int _key[300];
	int _map[300] = {0};
	memset(_map, 0, sizeof(int) * 300);
	memset(_key, -1, sizeof(int) * 300);
	for  (int i = 0; i < n; i++) {
		int first = -1;
		int second = -1;
		cin >> first >>  second;
		_map[first] += second;
		if (_key[first] == -1) {
			_key[first] = 1;
		}
	}
	for (int i = 0; i < 300; i++) {
		if (_key[i] == 1) cout << i << "\n" << _map[i] << endl;
	}
}