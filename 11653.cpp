#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, div = 2;
	cin >> n;
	while(1){
		if(n % div == 0) {
			cout << div << "\n";
			n /= div;
		}
		else div++;
		if(n == 1) break;
	}
}
