#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	while (getline(cin, str)) {
		int sum = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') sum++;
		}
		cout << sum << endl;
	}
}