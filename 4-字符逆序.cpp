#include <iostream>
#include <string>
using namespace std;

int main() {
	string source;
	while (getline(cin, source)) {
		for (int i = source.length()-1; i >= 0; i--) {
			cout << source[i];
		}
		cout << std::endl;
	}
}