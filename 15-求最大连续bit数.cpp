#include <iostream>
using namespace std;

int main() {
	int num;
	while (cin >> num) {
		int total = 0;
		int cur = 0;
		while (1) {
			if ((num & 0x1) == 1) {
				cur++;
			} else {
				total = cur > total ? cur : total;
				cur = 0;
				if (num == 0) break;
			}
			num = num >> 1;
		} 
		cout << total << endl;
	}
}