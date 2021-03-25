#include <bits/stdc++.h>

using namespace std;

int n, res = 3001;
int house[1001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int r, g, b;
		cin >> r >> g >> b;
		house[i][0] = r + min(house[i-1][1], house[i-1][2]);
		house[i][1] = g + min(house[i-1][0], house[i-1][2]);
		house[i][2] = b + min(house[i-1][0], house[i-1][1]);
	}
	res = min(house[n][0], house[n][1]);
	res = min(res, house[n][2]);
	cout << res;
	return 0;
}
