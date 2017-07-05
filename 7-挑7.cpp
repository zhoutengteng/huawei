#include <iostream>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		int sum = 0;
		for (int i = 1; i < n; i++) {
			if (i % 7 == 0) {
				sum++;
				continue;
			} 
			int x = i;
			while (x) {
				if (x % 10 == 7) {
					sum++;
					break;
				} else {
					x /= 10;
				}
			}

		}
		cout << sum << endl;
	}

}