#include <bits/stdc++.h>

using namespace std;

int mem[1000001];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n;
	mem[1] = 1;
	mem[2] = 2;
	if(n == 1) cout << 1;
	else if(n == 2) cout << 2;
	else{
		for(int i = 3; i <= n; i++){
			mem[i] = mem[i-1] + mem[i-2];
			mem[i] %= 15746; 
		}
		cout << mem[n];
	}
}


