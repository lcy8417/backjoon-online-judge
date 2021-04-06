#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		vector<vector<int> > dy(2, vector<int>(100001, 0));
		vector<vector<int> > v(2, vector<int>(n+1, 0));
		for(int i = 0; i <= 1; i++)
			for(int j = 1; j <= n; j++) cin >> v[i][j];
		dy[0][1] = v[0][1];
		dy[1][1] = v[1][1];
		for(int i = 2; i <= n; i++){
			dy[0][i] = v[0][i] + max(dy[1][i-1], dy[1][i-2]);
			dy[1][i] = v[1][i] + max(dy[0][i-1], dy[0][i-2]);
		}
		cout << max(dy[0][n], dy[1][n]) << "\n";

	}
	return 0;
}
