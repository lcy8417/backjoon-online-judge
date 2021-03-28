#include <bits/stdc++.h>
using namespace std;

int dy[1001];

int fac(int n){
	if(dy[n] != 0) return dy[n];
	if(n == 1) return 1;
	if(n == 0) return 1;
	else return dy[n] = (n * fac(n-1));
}

int main(){
	ios::sync_with_stdio(false);
	int n, k, res;
	cin >> n >> k;
	res = fac(n) / (fac(n-k) * fac(k));
	cout << res;
}	
