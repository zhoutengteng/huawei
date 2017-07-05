#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char **argv) {
    int n;
    int pInt[1024];
    while (cin >> n) {
      for (int i = 0; i < n; i++) {
		cin >> pInt[i];
      }
      int result[1024];
      for (int i = 0; i < n; i++) {
      	result[i] = 0;
      }

      for (int i = 0; i < n; i++) {
          int max = 0;
		  for (int j = i; j-1 >= 0; j--) {
		       if (pInt[i] > pInt[j-1] && result[j-1] > max) {
		       		max = result[j-1];
				}
		  }
		  result[i] = max+1;
      }
      int final = -1;
      for (int i = 0; i < n; i++) {
          if (result[i] > final) final = result[i];
      }
      cout <<  final << endl;
      

    }
    return 0;
}
