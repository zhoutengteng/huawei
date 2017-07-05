#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	if (str == "") return 0;
	int ascii[128] = {0};
	memset(ascii, 0, sizeof(int) * 128);
	for (int i = 0; i < str.length(); i++) {
		ascii[str[i]]++;
	}
	for (int i = ' '; i < 128; i++) {
		int max = 0;
		char result = ' ';
		for (char j = ' '; j <= 'z'; j++) {
			if (isspace(j) ||  isdigit(j) | isalpha(j)) {
				if (max < ascii[j]) {
					max = ascii[j];
					result = j;
				}
			}
		}
		if (max != 0) {
			cout << result;
			ascii[result] = 0;
		}
	}
	cout << endl;
}