#include <bits/stdc++.h>

using namespace std;

int tri[502][502];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, res = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++) {
			cin >> m;
			tri[i][j] = max(tri[i-1][j-1], tri[i-1][j]) + m;
		}
	}
	for(int i = 1; i <= n; i++)
		if(res < tri[n][i]) res = tri[n][i];
		
	cout << res;
	
	return 0;
}
