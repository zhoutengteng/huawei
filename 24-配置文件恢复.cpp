#include <iostream>
#include <string>
using namespace std;


bool isBegin(string& str1, string& str2) {
	int i = 0;
	if (str2.length() > str1.length()) return false;
	while (i < str2.length()) {
		if (str1[i] != str2[i]) return false;
		i++;
	}
	return true;
}


int main() {
	string str;
	string order[6] = {"reset what", "board fault", "where to add", "no board at all", "impossible", "install first"};
	string table_1[6] = {"reset", "reset", "board", "board","reboot","backplane"};
	string table_2[6] =  {"", "board", "add", "delet","backplane","abort"};
	while (getline(cin, str)) {
		int result = -1;
		int count = 0;
		if (str.length() == 0) continue; 
		if (str.find(" ", 0) == string::npos) {
			if (table_1[0].find(str, 0) != string::npos) {
				result = 0;
				count++;
			}
		} else {
			string str_first = str.substr(0, str.find(" ", 0));
			string str_second = str.substr(str.find(" ", 0) + 1, str.length() - (str.find(" ", 0) + 1));
			if (str_second.find(" ", 0) != string::npos) {
				str_second = str_second.substr(0, str_second.find(" ", 0));
			}
			for (int i = 1; i < 6; i++) {
				if (isBegin(table_1[i], str_first)&& isBegin(table_2[i], str_second)) {
					result = i;
					count++;
				}
			}
		}
		if (count == 1) {
			cout << order[result] << endl;
		} else {
			cout << "unkown command" << endl;
		}
	}
}