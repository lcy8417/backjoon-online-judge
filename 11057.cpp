#include <bits/stdc++.h>

using namespace std;

int dy[1001][10];

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	int res = 0;
	cin >> N;
	for(int i = 0; i <= 9; i++) {
		dy[1][i] = 1;
		res += dy[1][i];
	}
	for(int i = 2; i <= N; i++){
		for(int j = 1; j <= 9; j++){
			for(int k = j; k <= 9; k++){
				dy[i][j] += (dy[i-1][k] % 10007); 
				res += dy[i-1][k] % 10007;
			}
		}
	}
	cout << res % 10007;
	
	return 0;
}
