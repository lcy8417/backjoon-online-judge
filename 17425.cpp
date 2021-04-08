#include <bits/stdc++.h>
using namespace std;

vector <long long> dp(1000001);
int N, T;

void init(){
	for(int i = 1; i <= 1000000; i++){
		for(int j = i; j <= 1000000; j+=i){
			dp[j] += i;
		}
	}
	for(int i = 2; i <= 1000000; i++) dp[i] += dp[i-1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin >> T;
	while(T--){
		cin >> N;
		cout << dp[N] << "\n";
	}
}
