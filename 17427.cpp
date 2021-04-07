#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int N;
	long long res = 0;
	cin >> N;
	for(int i = 1; i <= N; i++) {
		int mul = N/i;
		res += mul*i;
	}
	
	cout << res;
}
