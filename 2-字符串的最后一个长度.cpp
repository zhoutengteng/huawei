#include <iostream>  
#include <string>  
#include <stdio.h>  
using namespace std;  
  
int main() {  
    int i = 0;  
    string c;  
    while(getline(cin, c)) {
        string::iterator ch =  c.begin();
        while (*ch != '\0') {  
            if (*ch++ == ' ') {  
                i = 0;  
            } else {  
                i++;  
            }  
        }
        cout << i << endl;  
    }        
    return 0;     
}  