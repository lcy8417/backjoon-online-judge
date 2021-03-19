#include <bits/stdc++.h>
using namespace std;

int a[300001];

int primeNumberSieve(int n){
	int cnt = 0;
	for(int i = 2; i <= 2 * n; i++) a[i] = i;
	for(int i = 2; i <= 2 * n; i++){
		if(a[i] == 0) continue;
		for(int j = i + i; j <= 2 * n; j += i) a[j] = 0;
	}
	for(int i = n + 1; i <= 2 * n; i++) if(a[i] != 0) cnt++;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	while(1){
	cin >> n;
	if(n == 0) break;
	cout << primeNumberSieve(n) << "\n";
	}
}
