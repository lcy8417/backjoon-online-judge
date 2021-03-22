#include <bits/stdc++.h>
using namespace std;

int Fac(int n){
	if(n == 0) return 1;
	if(n == 1) return 1;
	else return n * Fac(n-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << Fac(n);
}
