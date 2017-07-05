#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;





int main () {
  int dictLength;
  cin >> dictLength;
  cin.get();
  string* dict = new string[dictLength];
  for (int i = 0; i < dictLength; i++) {
  	getline(cin , dict[i]);
  }
  string target = "";
  getline(cin, target);
  int target_which = 0;
  cin >> target_which;

  char* buff = new char[target.length()];
  target.copy(buff, target.length(), 0);
  buff[target.length()] = '\0';
  string target_copy = string(buff);
  sort(target_copy.begin(), target_copy.end());
  string* result = new string[dictLength];
  int result_count = 0;
  do {
    for (int i = 0; i < dictLength; i++) {
    	if (target != target_copy && target_copy == dict[i]) {
    		result[result_count] = target_copy;
    		result_count ++;
    	} 
    }
  } while (next_permutation(target_copy.begin(), target_copy.end()));    ///获取下一个较大字典序排列

  // sort(result, result + result_count);

	if (target_which > result_count) {
		return 0;
	}

  cout << result_count  << endl;
  cout <<  result[target_which-1] << endl;

  // cout << endl;
  // for (int i = 0; i < result_count; i++) {
  // 	cout <<  result[i] << endl;
  // }
  delete []dict;
  delete []result;
  delete []buff;
  return 0;
}