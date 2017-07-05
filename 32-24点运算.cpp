#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;


void init(map<string, int>& mymap) {
	mymap["3"] = 3;
	mymap["4"] = 4;
	mymap["5"] = 5;
	mymap["6"] = 6;
	mymap["7"] = 7;
	mymap["8"] = 8;
	mymap["9"] = 9;
	mymap["10"] = 10;
	mymap["J"] = 11;
	mymap["Q"] = 12;
	mymap["K"] = 13;
	mymap["A"] = 1;
	mymap["2"] = 2;
}


string i2s(int a) {
	char str[10];
	sprintf(str,"%d",a);
	return string(str);
}




void recursion(int card[4], int card_index, bool& isfind, int curCalculator, vector<string>&  result) {
	for (int i = card_index; i < 4; i++) {
		int first = card[i];
		int card_copy[4];
		memcpy(card_copy,card, 4*sizeof(int));
		for (int j = i - 1; j >= card_index; j--) {
			card_copy[j+1] = card_copy[j];
		}
		card_copy[card_index] = first;
		if (card_index == 0) {
			result.push_back(i2s(first));
			recursion(card_copy, card_index+1, isfind, first, result);
			result.pop_back();
		} else {
			result.push_back("+");
			result.push_back(i2s(first));
			recursion(card_copy, card_index+1, isfind, curCalculator + first, result);
			result.pop_back();
			result.pop_back();

			result.push_back("-");
			result.push_back(i2s(first));
			recursion(card_copy, card_index+1, isfind, curCalculator - first, result);
			result.pop_back();
			result.pop_back();

			result.push_back("*");
			result.push_back(i2s(first));
			recursion(card_copy, card_index+1, isfind, curCalculator * first, result);
			result.pop_back();
			result.pop_back();

			if (curCalculator % first == 0) {
				result.push_back("/");
				result.push_back(i2s(first));
				recursion(card_copy, card_index+1, isfind, curCalculator / first, result);
				result.pop_back();
				result.pop_back();

			}

		}
	}
	if (card_index == 4 && !isfind) {
		if (curCalculator == 24) {
			for (vector<string>::iterator it = result.begin(); it < result.end(); it++) {
				cout << *it;
			}
			cout << endl;
			isfind = true;
		}
		return;
	}
}




int main() {
	map<string, int> mymap;
	init(mymap);
	int card[4];
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		if (mymap.find(str) == mymap.end()) {
			cout << "ERROR" << endl;
			return 0;
		}
		card[i] = mymap[str];
	}
	sort(card, card+4);
	vector<string> result;
	bool isfind = false;
	recursion(card, 0, isfind, -1, result);
	if (isfind == false) {
		cout << "NONE" << endl;
	}
	// for (int i = 0; i < 4; i++) {
	// 	cout << card[i] << endl;
	// }


}



// void Meeting::addParticipator(const std::string &t_participator) {
	// for (std::vector<string> it = m_participators.begin(); it != m_participators.end(); it++) {
	// 	if (t_participator.compare(*it)	== 0) return
	// }
	// //注意这里是引用，如果是要求备份的话，你要复制一份字符串
	// m_participators.push_back(t_participator);
// }


// void Meeting::removeParticipator(const std::string &t_participator) {
	// for (std::vector<string> it = m_participators.begin(); it != m_participators.end(); it++) {
	// 	if (t_participator.compare(*it)	== 0) {
	// 		m_participators.erase(it);
	// 		return;
	// 	}
	// }
// }
