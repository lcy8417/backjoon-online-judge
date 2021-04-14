#include <iostream>
#include <vector>
using namespace std;

long long dy[201][201];
long long MOD = 1000000000;
int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	dy[0][0] = 1LL;
	for(int i = 0; i <= n; i++) {
		dy[1][i] = 1;
	}
	for(int t = 2; t <= k; t++){
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= i; j++){
				dy[t][i] += dy[t-1][i-j];
				dy[t][i] %= MOD;
			}
		}
	}
	cout << dy[k][n] % MOD;
}
