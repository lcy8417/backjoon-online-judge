#include <bits/stdc++.h>

using namespace std;

long long int pn[101];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	long long int res = 0;
	cin >> n;
	pn[1] = 1; pn[2] = 1; pn[3] = 1; pn[4] = 2; pn[5] = 2;
	pn[6] = 3; pn[7] = 4; pn[8] = 5; pn[9] = 7; pn[10] = 9; 
	for(int i = 1; i <= n; i++){
		cin >> m;
		if(m <= 10) cout << pn[m] << "\n";
		else {
			for(int i = 11; i <= m; i++)
				pn[i] = pn[i-1] + pn[i-5];
			cout << pn[m] << "\n";
		}

	}
	return 0;
}
