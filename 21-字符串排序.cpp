#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool compare(char a, char b) {
    if (isalpha(a) && isalpha(b)) {
        return tolower(a) <  tolower(b);
    } else {
        return a < b;
    }
}

int main() {
    string str;
    while (getline(cin ,str)) {
        char buffer[300];
        size_t length =  str.copy(buffer, str.length(), 0);
        buffer[length] = '\0';
        for (int i = 0; i < str.length(); i++) {
            if (!isalpha(str[i])) str[i]='1';
        }
        stable_sort(str.begin(), str.end(), compare);
        string str_copy = string(buffer);
        // cout << str_copy << endl;
        // cout << str << endl;
        int begin = 0;
        for (int i = 0; i < str.length(); i++) {
            if (!isalpha(str[i])) continue;
            begin = i;
            break;
        }
        for (int i = 0; i < str_copy.length(); i++) {
            if (!isalpha(str_copy[i])) continue;
            str_copy[i] = str[begin++];
        }
        cout << str_copy << endl;
    }
}
//A Famo/us Sayi/ng: Much A/do Ab/out Not/hing (2012/8).
