#include <iostream>
#include <string>
using namespace  std;

 typedef enum __order {
	 LEFT = 'A',
	 RIGHT = 'D',
	 UP = 'W',
	 DOWN = 'S'
} _order;

bool nextorder(string& str, _order& order, int& step, int& nextIndex) {
	int index = str.find_first_of(';', nextIndex);
	string str1 = str.substr(nextIndex, index-nextIndex);
	//printf("jieqv=>%s , index=>%d\n", str1.c_str(), index);
	nextIndex = index+1;
	if (str1.length() != 3&& str1.length() != 2) return false;
	if (!isalpha(str1[0])) return false;
	if (!isdigit(str1[1])) return false;
	if (str1.length() == 3 && !isdigit(str1[2])) return false;
	if (toupper(str1[0]) == 'A') order = LEFT;
	if (toupper(str1[0]) == 'D')  order = RIGHT;
	if (toupper(str1[0]) == 'W') order = UP;
	if (toupper(str1[0]) == 'S')  order = DOWN;
	if (str1.length() == 3) {
		step = (str1[1] - '0') * 10 + str1[2] - '0';
	} else {
		step = str1[1] - '0';
	}
	return true;
		
}

void move(int& x, int& y, _order order, int step) {
	if (order == LEFT) {
		x -= step;
		return;
	}
	if (order == RIGHT) {
		x += step;
		return;
	}
	if (order == UP) {
		y += step;
		return;
	}
	if (order == DOWN) {
		y -= step;
		return;
	} 
}


int main() {
	string str;
	while (getline(cin, str)) {
		_order order = LEFT;
		int step = -1;
		int nextIndex = 0;
		int x = 0;
		int y = 0;
		while (nextIndex < str.length()-1) {
			if (nextorder(str, order, step, nextIndex)) {
				move(x, y, order, step);
			//	cout << x << ',' << y << endl;
			}
		}
		cout << x << ',' << y << endl;
	}
	return 0;
}
