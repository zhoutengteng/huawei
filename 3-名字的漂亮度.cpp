#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char str[129];
		cin >> str;
		int alph[26] = {0};
		char* ch = str;

		while (*ch != '\0') {
			// cout << *ch << "--?>" << std::endl;
			if (*ch >= 'a' && *ch <= 'z') {
				alph[*ch - 'a']++;
			} else {
				alph[*ch - 'A']++;
			}
			ch++;
		}
		for (int j = 0; j < 25; j++) {
			for (int jj = 0; jj < 25; jj++) {
				if (alph[jj+1] > alph[jj]) {
					int a = alph[jj+1];
					alph[jj+1] = alph[jj];
					alph[jj] = a;
				}
			}
		}

		int base = 26;
		int sum = 0;
		for (int j = 0; j < 26; j++) {
			// cout << alph[j] << "===" << std::endl;
			sum += base * alph[j];
			base--;
		}
		cout << sum << endl;
	}

}
