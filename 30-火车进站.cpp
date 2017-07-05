#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int n = 0;
int* pArr = NULL;

void handle(const int index, stack<int> s, vector<int> v) {
    for (int i = s.size(); i >=0; i--) {
        stack<int> sTemp(s);
        vector<int> vTemp(v);
        //从栈里面出 i 个到队列里面去
        for (int j = 1; j <= i; j++) {
            int top = sTemp.top();
            sTemp.pop();
            vTemp.push_back(top);
        }
        sTemp.push(pArr[index]);
        if (n - 1 == index) {
            //输出结果
            static bool isFirst = true;
            vector<int> vRes;
            if (!isFirst)
                cout << endl;

            for (int i = 0; i < vTemp.size(); i++)
                vRes.push_back(vTemp[i]);

            while (!sTemp.empty())
            {
                int top = sTemp.top();
                sTemp.pop();
                vRes.push_back(top);
            }
            int i = 0;
            for (i = 0; i < vRes.size() - 1; i++)
                cout << vRes[i] << " ";
            cout << vRes[i];
            isFirst = false;
        }
        else
        {
            handle(index + 1, sTemp, vTemp);
        }
    }
}

int main(void)
{
    cin >> n;
    pArr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> pArr[i];

    stack<int> s;
    vector<int> v;
    handle(0, s, v);

    delete[] pArr;

}