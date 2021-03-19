#include <bits/stdc++.h>
using namespace std;

int a[1000001];

void primeNumberSieve(int n, int m){ 
	for(int i = 2; i <= m; i++) a[i] = i;
	for(int i = 2; i <= m; i++){
		if(a[i] == 0) continue;
		for(int j = i + i; j <= m; j += i) a[j] = 0;
	}
	for(int i = n; i <= m; i++) if(a[i] != 0) cout << i << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	primeNumberSieve(n, m);
}
