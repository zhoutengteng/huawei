#include <iostream>
using namespace std;




void solve(int sum, int parts, int min, int& result) {
	if (parts == 1 && sum >= min) {
		result++;
		// cout << sum << endl;
		return;
	} 
	for (int i = min; i <= sum; i++) {
		solve(sum-i, parts-1, i, result);
	}
}


int main() {
	int sum, parts;
	int min = 0;
	cin >> sum >> parts;
	int result = 0;
	solve(sum, parts, min, result);
	cout << result << endl;

}