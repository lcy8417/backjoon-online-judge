#include <bits/stdc++.h>

using namespace std;

int c[101];
int dy[10001];
int n, k, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	dy[0] = 1;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++){
		for(int j = c[i]; j <= k; j++){
			dy[j] += dy[j-c[i]];
		}
	}
	cout << dy[k];
	return 0;
}
