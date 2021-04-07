#include <bits/stdc++.h>

using namespace std;

bool isPrimeNumber(int n){
	for(int i = 2; i <= (int)sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	int N, a=0, b=0;
	cin.tie(0);
	cout.tie(0);
	while(1){
		cin >> N;
		if(!N) break;
		for(int i = 2; i <= N; i++){
			if(isPrimeNumber(i) && isPrimeNumber(N-i)){
				a = i;
				b = N-i;
				break;
			}
		}
		if(a==0 && b==0){
			cout << "Goldbach's conjecture is wrong." << "\n";
		}else cout << N << " = " << a << " + " << b << "\n";
	}
	return 0;
}
