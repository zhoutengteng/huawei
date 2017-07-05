#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

/*
    实现对长度不同的字符串，3个联结
*/



int main()
{
	int dist[100][100], s = 0, n = 0, max = 0, start = 0, end = 0;

	string temp,result;
	vector<string> in;
	int path[100][100];

	memset(dist, 0, sizeof(int)*10000);
	memset(path, -1, sizeof(int)*10000);

	while (cin>>temp)
	{
		in.push_back(temp);
		n++;
	}
	if(in.empty()) return 0;

	//初始化有向图
	for (int i = 0; i < n; i++)
	{
    		temp = in[i].substr(in[i].length()-3, 3);
    		for (int j = 0; j < n; j++)
    		{
    			if (i != j)
    			{
    				if (in[j].substr(0, 3).compare(temp) == 0)
    				{
    					dist[i][j] = in[i].length()-3;
    				}
    			}
    		}
	}

	//动态规划实现弗洛伊德算法
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dist[i][k] != 0 && dist[k][j] != 0)
				{
					if (dist[i][k] + dist[k][j]>dist[i][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						path[i][j] = k;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max<dist[i][j])
			{
				max = dist[i][j];
				start = i;
				end = j;
			}
		}
	}

	temp = "";
	result = in[start].substr(0, in[start].length()-3);
	int mid = path[start][end];

	while (mid >= 0)
	{
		temp = in[mid].substr(0, in[mid].length()-3) + temp;
		mid = path[start][mid];
	}

	result += temp;
	result += in[end];

	cout << result << endl;
	return 0;
}

//AABCC ABCD BCCE BCDE CCEEF BCCE CCEG CEGF
