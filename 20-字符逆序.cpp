#include <iostream>
#include <string>
using namespace std;

void trans(string& src, int begin, int end) {
    while (begin < end) {
        char a = src[begin];
        src[begin] = src[end];
        src[end] = a;
        begin ++;
        end--;
    }
}




int main() {
    string str;
    while (getline(cin, str)) {
        int pos = 0;
        while ((str.find_first_of(" ", pos)) != -1) {
            trans(str, pos, str.find_first_of(" ",pos)-1);
            pos = str.find_first_of(" ",pos) + 1;
        }
        trans(str, pos, str.length()-1);
        trans(str, 0, str.length()-1);
        cout << str << endl;
    }
}
