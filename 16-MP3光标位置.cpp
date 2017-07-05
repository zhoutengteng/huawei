#include <iostream>
#include <stdio.h>
using namespace std;


void init(int* pCurDspSongLst, int n) {
	for (int i = 1; i <= n; i++) {
		pCurDspSongLst[i-1] = i;
	}

}




void InputPreCondition2(int iTotalItemsNum,char* pCommandLst, int* pCurDspSongLst, char* pCurDspSongLstStr, int* iCurItemNo) {
	int n = 4;
	if (iTotalItemsNum >= 4) {
		n = 4;
	} else {
		n = iTotalItemsNum;
	}
	init(pCurDspSongLst, n);

	while (*pCommandLst != '\0') {
		if (*pCommandLst == 'U') {
			if (*iCurItemNo == pCurDspSongLst[0]) {
				if (pCurDspSongLst[0] - 1 == 0) {
					pCurDspSongLst[n-1] = iTotalItemsNum;
					for (int i = n; i-2 >= 0; i--) {
						pCurDspSongLst[i-2] = pCurDspSongLst[i-1] - 1;
					}
				} else {
					pCurDspSongLst[0] -= 1;
					for (int i = 0; i+1 < n ; i++) {
						pCurDspSongLst[i+1] = pCurDspSongLst[i] + 1;
					}
				}
	
			} 
			*iCurItemNo = (*iCurItemNo -1) == 0 ? iTotalItemsNum : (*iCurItemNo - 1);
		} else {
			if (*iCurItemNo == pCurDspSongLst[n-1]) {
				if (pCurDspSongLst[n-1] + 1 > iTotalItemsNum) {
					pCurDspSongLst[0] = 1;
					for (int i = 0; i+1 < n ; i++) {
						pCurDspSongLst[i+1] = pCurDspSongLst[i] + 1;
					}
				} else {
					pCurDspSongLst[0] += 1;
					for (int i = 0; i+1 < n ; i++) {
						pCurDspSongLst[i+1] = pCurDspSongLst[i] + 1;
					}
				}
	
			} 
			*iCurItemNo = (*iCurItemNo + 1) > iTotalItemsNum ? 1 : (*iCurItemNo + 1);
		}
		pCommandLst++;

	}
	for (int i =0 ; i < n; i++) {
		if (i == 0) {
			sprintf(pCurDspSongLstStr, "%d",  pCurDspSongLst[i]);

		} else {
			sprintf(pCurDspSongLstStr, "%s %d", pCurDspSongLstStr, pCurDspSongLst[i]);
		}
	}
	cout << pCurDspSongLstStr << endl << *iCurItemNo << endl;

}



void InputPreCondition(int iTotalItemsNum,char* pCommandLst, char* pCurDspSongLstStr, int* iCurItemNo) {
	int pCurDspSongLst[4];
	InputPreCondition2(iTotalItemsNum, pCommandLst, pCurDspSongLst, pCurDspSongLstStr, iCurItemNo);
}

int main() {
	int totalMP3;
	char order[10240];
	while (cin >> totalMP3 >> order) {
		char pCurDspSongLst[100] = "";
		int first = 1;
		InputPreCondition(totalMP3, order, pCurDspSongLst, &first);
	}
}