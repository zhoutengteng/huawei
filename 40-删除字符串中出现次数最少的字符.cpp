#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

// #define DEBUG_PRINT

int main() {
    string str;
    cin >> str;
    int alpha[26];
    for (int i = 0; i < 26; i++) {
        alpha[i] = 1000;
    }
    for (int i = 0; i < str.length(); i++) {
        if (alpha[str[i] - 'a'] == 1000) {
            alpha[str[i] - 'a'] = 1;
        } else {
            alpha[str[i] - 'a']++;
        }
    }
    std::vector<char> alpha_delete;
    int min_alpha_num = 20 * 8 + 1;
    for (int i = 0; i < 26; i++) {
        char min_alpha = 'a';
        for (int j = 0; j < 25-i; j++) {
            if (alpha[j+1] > alpha[j]) {
                swap(alpha[j+1], alpha[j]);
            } else {
                min_alpha = j + 1 + 'a';
            }
        }
        if (alpha[25-i] <= min_alpha_num && alpha[25-i] != 0) {
            alpha_delete.push_back(min_alpha);
            min_alpha_num = alpha[25-i];
        } else {
            if (alpha[25-i] != 0) break;
        }
    }
#ifdef DEBUG_PRINT
    for (int i = 0; i < 26; i++) {
        cout << alpha[i] << " ";
    }
    cout << endl;
    for (std::vector<char>::iterator it = alpha_delete.begin(); it != alpha_delete.end(); it++) {
        cout << "-> "  << *it << endl;
    }
#endif

    for (int i = 0; i < str.length(); i++) {
        if (find(alpha_delete.begin(),alpha_delete.end(),str[i]) == alpha_delete.end()) cout << str[i];
    }
    cout << endl;
}
