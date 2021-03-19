#include <bits/stdc++.h>
using namespace std;

int a[10001];

bool isPrime(int x){
	int end = (int)sqrt(x);
	for(int i = 2; i <= end; i++){
		if(x % i == 0) return false;
	}
	return true;
}

void PrimeNumber(int m){
	int x = 0, y = 10001;
	for(int i = 1; i <= m; i++) a[i] = 1;
	for(int i = 2; i <= m; i++){
		if(a[i] == 0) continue;
		for(int j = i + i; j <= m; j += i) a[j] = 0;
	}
	int end = (int)sqrt(m);
	for(int i = 2; i <= m; i++) {
		if(a[i] != 0){
			if(isPrime(m-i)){ 
				if(y - x > (m - i) - i && (m - i) - i >= 0){
					x = i;
					y = m - i;
				}
			}
		}
	}
	cout << x << " " << y << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> m;
		PrimeNumber(m);
	}
}
