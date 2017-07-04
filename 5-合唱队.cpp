#include <iostream>
using namespace std;

void LAS(int*& save,  int*& arr, int N) {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && save[i] < save[j] + 1 ) {
				save[i] = save[j] + 1;
			}
		}
	}
}

void LAS_reserve(int*& save,  int*& arr, int N) {
	for (int i = N-2; i >= 0; i--) {
		for (int j = N-1; j > i; j--) {
			if (arr[i] > arr[j] && save[i] < save[j] + 1 ) {
				save[i] = save[j] + 1;
			}
		}
	}
}




int main() {
	int N;
	while (cin >> N) {
		int* arr = new int[N];
		int* save_1 = new int[N];
		int* save_2 = new int[N];
		for(int i = 0; i < N; i++) {
			save_1[i] = save_2[i] = 1;
		}
		for (int i = 0; i < N; i++) {
	        cin >> arr[i];
		}
		LAS(save_1, arr, N);
		LAS_reserve(save_2, arr, N);
		// for (int i = 0; i < N; i++) {
		// 	cout << "LCS " << i << " : " << save_1[i] << std::endl;
		// }
		// cout << std::endl;
		// for (int i = 0; i < N; i++) {
		// 	cout << "LCS " << i << " : " << save_2[i] << std::endl;
		// }
		int max = -1;
		for (int i = 0; i < N; i++) {
			if (save_1[i] + save_2[i] - 1 > max) {
				max = save_1[i] +  save_2[i] - 1;
			}
		}
		cout << N - max << endl;
		delete[] save_1;
		delete[] save_2;
		delete[] arr;
	}
}