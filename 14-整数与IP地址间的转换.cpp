#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
	string ipstr;
	unsigned int ipint;
	while(cin >> ipstr >> ipint) {
		int a1,a2,a3,a4;
		sscanf(strtok((char*)(ipstr.c_str()), ".") ,"%d",&a1);
		sscanf(strtok(NULL, ".") ,"%d",&a2);
		sscanf(strtok(NULL, "."),"%d",&a3);
		sscanf(strtok(NULL, "."),"%d",&a4);
		cout << (a1 << 24) + (a2 << 16) + (a3 << 8) + a4 << endl;
		cout << ((ipint >> 24) & 0xff)<< '.' << ((ipint >> 16) & 0xff) << '.' << ((ipint >> 8) & 0xff ) << '.' << (ipint & 0xff) << endl;
	}
}