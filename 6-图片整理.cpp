#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(char a, char b) {
	return a < b;
}

int main() {
	string str;
	getline(cin, str);
	sort(str.begin(), str.end(), compare);
	cout << str << std::endl;
}