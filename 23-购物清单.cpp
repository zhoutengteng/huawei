#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

#define MAX_N 3200
#define MAX_M 60

struct goods
{

	int v;
	int p;
	int q;
};

int main()
{

	int value, num, i, j, v, p, q, w;
	goods g;
	vector<goods> goodsList;
	int f[MAX_M][MAX_N];
	bool flag[MAX_M][MAX_N];

	//初始化
	memset(f, 0, MAX_M * MAX_N * sizeof(int));
	memset(flag, false, MAX_M * MAX_N * sizeof(bool));
	cin >> value >> num;

	for (i = 0; i<num; i++)
	{
		cin >> g.v >> g.p >> g.q;
		goodsList.push_back(g);
	}

	for (i = 1; i <= num; i++)
	{
		for (j = 0; j <= value; j++)
		{
			w = goodsList[i - 1].v*goodsList[i - 1].p;

			if (goodsList[i - 1].q == 0)
			{
				if (j < goodsList[i - 1].v)
				{
					f[i][j] = f[i - 1][j];
				}
				else
				{
					flag[i][j] = true;
					f[i][j] = max(f[i - 1][j], f[i - 1][j - goodsList[i - 1].v] + w);
				}
			}
			else
			{
				if (j < goodsList[i - 1].v)
				{
					f[i][j] = f[i - 1][j];
				}
				else
				{
					if (flag[i][j - goodsList[i - 1].v])
					{
						f[i][j] = max(f[i - 1][j], f[i - 1][j - goodsList[i - 1].v] + w);
					}
					else
					{
						f[i][j] = f[i - 1][j];
					}
				}
			}
		}
	}

	cout << f[num][value] << endl;

	return 0;
}

//1000 5 800 2 0 400 5 1 300 5 1 400 3 0 500 2 0
/*
那么有  F[i][v]=max{F[i-1][v],F[i-1][v-C[i]]+W[i]}

现在来解释一下上面这个最关键的状态转移方程！

当前背包容量为v，即将处理第i件物品。显然有如下两种方案，出现了最优子结构性质：

a.若第i件物品加入背包，装入这前i件物品获得的最大价值F[i][v]，必然等于第i件物品的价值W[i]再加上向容量为v-C[i]的背包装入前i-1件物品这个子问题的最大价值F[i-1][v-C[i]] (先把第i件物品加入背包，然后考虑安排剩余的空间容量)

b.若不加入第i件物品，装入这前i件物品的获得的最大价值F[i][v]，必然等于向容量为v的背包装入前i-1件物品这个子问题获得的最大价值F[i-1][v]

*/
