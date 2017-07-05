#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	string str2;
	while (getline(cin , str1) && getline(cin , str2)) {
		for (int i = 0; i < str1.length(); i++) {
			if (str1[i] >= 'a' && str1[i] <= 'z') {
				cout << char(('a' + ((str1[i] - 'a' + 1 ) % 26)) - ('a' - 'A'));
			} else if (str1[i] >= 'A' && str1[i] <= 'Z') {
				cout << char(('A' + ((str1[i] - 'A' + 1) % 26)) + ('a' - 'A')) ;
			} else if (str1[i] >= '0' && str1[i] <= '9') {
				cout << char(('0' + ((str1[i] - '0' + 1) % 10)));
			} else {
				cout << str1[i];
			}
		}
		cout << std::endl;
		for (int i = 0; i < str2.length(); i++) {
			if (str2[i] >= 'a' && str2[i] <= 'z') {
				cout << char(((str2[i] - ('a' - 'A')  - 'A' - 1 + 26) % 26) + 'A') ;
			} else if (str2[i] >= 'A' && str2[i] <= 'Z') {
				cout << char(((str2[i] + ('a' - 'A')  - 'a' - 1 + 26) % 26) + 'a' );
			} else if (str2[i] >= '0' && str2[i] <= '9') {
				cout << char(('0' + ((str2[i] - '0' - 1 + 10) % 10))) ;
			} else {
				cout << str2[i];
			}
		}
		cout << std::endl;
	}
}