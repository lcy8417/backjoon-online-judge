#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int main() {
	ios_base::sync_with_stdio(false);
	int n, m, mini = 10001, sum = 0;
	cin >> n >> m;
	
	for(int i = n; i <= m; i++){
		if(i == 1) continue;
		bool flag = false;
		for(int j = 2; j < i; j++)
			if(i % j == 0) flag = true;
		if(!flag) {
			sum += i;
			mini = min(mini, i);
		}
	}
	if(mini == 10001) cout << -1;
	else cout << sum << "\n" << mini;
}
