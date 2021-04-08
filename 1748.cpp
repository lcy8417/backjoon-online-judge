#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	int N;
	long long cnt = 1, sum = 9, res = 0, mul = 9;
	cin >> N;
	while(sum < N){
		res += mul * cnt;
		cnt++;
		sum = sum * 10 + 9;
		mul *= 10;
	}
	N -= (sum / 10);	
	res += N * cnt;
	cout << res;
	return 0;
}
