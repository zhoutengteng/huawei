#include <iostream>

using namespace std;

const long BILLION = 1000 * 1000 * 1000;
const long MILLION = 1000 * 1000;
const long THOUSAND = 1000;

string numMap[20] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
					"eleven","twelve", "thirteen","fourteen","fifteen","sixteen","seventeen",
					"eighteen","nineteen"};
string integer[10] = {"error", "error", "twenty", "thirty", "forty", "fifty","sixty","seventy", "eighty", "ninety"};

//0~999
string under1000(long num) {
	string result = "";
	//exclude 100
	if (num == 100) {
		result += "one hundred";
		return result;
	}
	if (num / 100 != 0) {
		result += numMap[num/100] + " hundred and ";
		num = num % 100;
	}
	if (num >= 0 && num <= 19) {
		result += numMap[num];
	} else if (num >= 20 && num <= 99 && num % 10 == 0) {
		result += integer[num / 10];
	} else if (num >= 20 && num <= 99 && num % 10 != 0) {
		result += integer[num/10] + " " + numMap[num%10];
	}
	return result;
}

//1234567891 = 1000000000 + 234000000 + 567000 + 891

void handler(long num) {
	string result = "";
	if (num == 0) {
		cout << "zero" << endl;
		return;
	}
	if (num / BILLION != 0) {
		result += under1000(num / BILLION) + " billion ";
		num = num % BILLION;
	}
	if (num / MILLION != 0) {
		result += under1000(num / MILLION) + " million ";
		num = num % MILLION;
	}
	if (num / THOUSAND != 0) {
		result += under1000(num / THOUSAND) + " thousand ";
		num = num % THOUSAND;
	}
	if (num != 0) {
		result += under1000(num);
	}
	int ok = 1;
	for (int i = 0; i < result.length(); i++) {
		if (result[i] == ' ') {
			if (ok) {
				cout << result[i];
				ok = 0;
			}
		} else {
			cout << result[i];
			ok = 1;
		}
	}
	cout << endl;
}


int main() {
	long num;
	while (cin >> num) {
		if (num >= 0 && num <10000000000)
			handler(num);
		else
			cout<<"error" << endl;
	}
}
