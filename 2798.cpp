#include <bits/stdc++.h>
using namespace std;

int card[101];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, mini = 300001, res = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> card[i];
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			for(int k = j+1; k <= n; k++) {
				int sum = card[i] + card[j] + card[k];
				if(m >= sum && mini > m - sum){
					mini = m - sum;
					res = sum;
				}
			}
		}
	}
	cout << res;
}
