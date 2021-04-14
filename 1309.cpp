#include <bits/stdc++.h>
#define MOD 9901
using namespace std;

int dy[100001][3];


int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	dy[1][0] = 1;
	dy[1][1] = 1;
	dy[1][2] = 1;
	for(int i = 2; i <= n; i++){
		dy[i][0] = dy[i-1][1]%MOD+dy[i-1][2]%MOD;
		dy[i][1] = dy[i-1][1]%MOD+dy[i-1][2]%MOD;
		dy[i][2] = dy[i-1][0]%MOD+dy[i-1][1]%MOD+dy[i-1][2]%MOD;
	}
		
	cout << (dy[n][0]%MOD+dy[n][1]%MOD+dy[n][2]%MOD)%MOD;
}
