#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

bool compare(string first, string second) {
    unsigned int i=0;
    while ( (i<first.length()) && (i<second.length()) ) {
    	if (tolower(first[i])<tolower(second[i])) return true;
    	else if (tolower(first[i])>tolower(second[i])) return false;
    	++i;
  	}
   return (first.length() < second.length());
}

int main() {
	string strArray[100];
	int index = 0;
	while(getline(cin,strArray[index])) {
		index++;
	}
	for (int index_ = 0; index_ <  index; index_++) {
		string str = strArray[index_];
		if (str.length() <= 8) {
			cout << "NG" << endl;
			continue;
		}
		int num[4] = {0,0,0,0};
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'a'&& str[i] <= 'z') {
				num[0] = 1;
			} else if(str[i] >= 'A'&& str[i] <= 'Z') {
				num[1] = 1;
			} else if(str[i] >= '0'&& str[i] <= '9') {
				num[2] = 1;
			} else {
				num[3] = 1;
			}
		}
		if (num[0] + num[1] + num[2] + num[3] < 3) {
			cout << "NG" << endl;
			continue;
		} 

		list<string> list1;
		for (int i = 0; i < str.length(); i++) {
			for (int j = i+2; j < str.length(); j++) {
				list1.push_back(str.substr(i, j - i + 1));
			}
		}

		list1.sort(compare);
		int open = 1;
		list<string>::iterator it;
		for (it = list1.begin(); it !=  list1.end(); it++) {
			list<string>::iterator it2 = it;
			it2++;
			if (it2 == list1.end()) break;
			if ((*it).compare(*it2) == 0) {
				cout << "NG" << endl;
				open = 0;
				break;
			}
		}
		if (open) {
			cout << "OK" << endl;
		}
	}
}