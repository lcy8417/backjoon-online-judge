#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#define endl '\n'
using namespace std;

int map[10][10];
vector<pair<int, int>> slotV;

bool chkSq(int r, int c, int num)
{
	int pivR = r / 3;
	int pivC = c / 3;
	for (int i = pivR * 3; i < pivR * 3 + 3; ++i)
	for (int j = pivC * 3; j < pivC * 3 + 3; ++j)
	if (map[i][j] == num)
		return false;
	return true;
}

bool chkC(int c, int num)
{
	for (int i = 0; i < 9; ++i)
	if (map[i][c] == num)
		return false;
	return true;
}

bool chkR(int r, int num)
{
	for (int j = 0; j < 9; ++j)
	if (map[r][j] == num)
		return false;
	return true;
}

void DFS(int idx)
{
	if (idx == slotV.size())
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		exit(EXIT_SUCCESS);
	}

	for (int num = 1; num <= 9; ++num)
	{
		int curR = slotV[idx].first;
		int curC = slotV[idx].second;
		if (chkC(curC, num) && chkR(curR, num) && chkSq(curR, curC, num))
		{
			map[curR][curC] = num;
			DFS(idx + 1);
			map[curR][curC] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				slotV.push_back({ i, j });
		}
	}
	DFS(0);
}