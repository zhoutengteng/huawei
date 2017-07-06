#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i  == 0) return false;
    }
    return true;
}



//状态方程感觉不对，不应该使用DP方程
int primePairsTest(int* num, int size) {
    int dp[100];
    memset(dp, 0, sizeof(int) * 4);
    for (int i = 1; i < size; i++) {
        int max_ = -1;
        for (int j = 0; j < i; j++) {
            if (j != 0) {
                if (isPrime(num[i] + num[j])) {
                    cout << "num[" << i << "]:" << num[i] << ",num[" << j << "]:" << num[j] << endl;
                    max_ = max(max_,dp[i-1] + dp[j-1] - dp[j+1] + 1);
                } else {
                    max_ = max(max_, dp[i-1]);
                }
            } else {
                if (isPrime(num[i] + num[j])) {
                    cout << "num[" << i << "]:" << num[i] << ",num[" << j << "]:" << num[j] << endl;
                    max_ = max(max_,dp[i-1] + 0 - dp[j+1] + 1);

                } else {
                    max_ = max(max_, dp[i-1]);
                }
            }
            dp[i] = max(max_, dp[i]);
        }
    }
    for (int i = 0; i < size; i++) {
        cout << dp[i] << endl;
    }
    return dp[size-1];
}

int main() {
    int num[100];
    memset(num, 0, sizeof(int) * 4);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    if (N < 2)
        cout << 0 << endl;
    else
        cout << primePairsTest(num, N) << endl;
}
