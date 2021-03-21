#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, res = 1000001;
	cin >> n;
	for(int i = n/2; i <= n; i++){
		int temp = i;
		int sum = i;
		while(temp > 0){
			sum += temp %10;
			temp /= 10;
		}
		if(sum == n && i < res) res = i;
	}
	if(res == 1000001) cout << 0;
	else cout << res;
}
