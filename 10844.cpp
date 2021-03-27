#include <bits/stdc++.h>
using namespace std;

int dy[101][10];
int res;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i <= 9; i++) dy[1][i] = 1;
	
	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= 9; j++){
			if(j-1 >= 0) dy[i][j] += dy[i-1][j-1];
			if(j+1 <= 9) dy[i][j] += dy[i-1][j+1];
			dy[i][j] %= 1000000000;
		}
	}
	for(int i = 1; i <= 9; i++) {
		res += (dy[n][i]);
		res %= 1000000000;
	}
	cout << res % 1000000000;
}
