#include <iostream>
using namespace std;

int main() {
	unsigned int x;
	unsigned char max = 0;
	unsigned char count = 0;
	while (cin >> x) {
		if (x > 255 | x < 0) {
			continue;
		}
		while (x != 0) {
			//scout  << "x = " << (char)(x + '0')<< endl;
			if (x & 0x1 == 1) {
				if (count == 0) {
					count = 1;
				} else {
					count++;
				}
				max = count > max ? count : max;
			} else {
					count = 0;
			}
			x = x >> 1;
		}
		cout <<  (char)(max + '0') << endl;
		count = 0;
		max = 0;
		count = 0;
	}
	return 0;

}
