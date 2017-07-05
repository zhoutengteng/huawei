#include <iostream>
#include <string>
using namespace std;

void mysort(string& str) {
	for (int i = 0; i < str.length() - 2; i = i + 2) {
		for (int  j = 0; j < str.length() - 2; j = j + 2) {
			if (str[j+2] < str[j]) swap(str[j+2], str[j]);
			if (str[j+3] < str[j+1]) swap(str[j+3], str[j+1]);
		}
	}

}




void reverse(char& oneChar) {
	// cout << oneChar << " ";
	int a = 0;
	if (isdigit(oneChar)) {
		a = oneChar - '0';
	} else if (oneChar >= 'A' && oneChar <= 'F')  {
		a = oneChar - 'A' + 10;
	} else if (oneChar >= 'a' && oneChar <= 'f') {
		a = oneChar - 'a' + 10;
	} else {
		return;
	}
	oneChar = ((a >> 3) & 0x01) + ((a >> 2) & 0x01) * 2 +  ((a >> 1) & 0x01) * 4 + (a & 0x01) * 8;
	if (oneChar < 10) {
		oneChar += '0';
		// cout << oneChar << endl;
		return;
	}
	oneChar = (oneChar - 10) + 'A';
	// cout << oneChar << endl;

	return;
}

int main() {
	string str1, str2;
	// getline(cin, str1);
	// getline(cin, str2);
	cin >> str1 >> str2;
	string str3 = str1 + str2;
	// cout << str3 << endl;
	mysort(str3);
	// cout << str3 << endl;
	for (int i = 0; i < str3.length(); i++) {
		reverse(str3[i]);
	}
	cout << str3 << endl;

}


