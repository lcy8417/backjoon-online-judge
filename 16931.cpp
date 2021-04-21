#include <iostream>

using namespace std;

int a[101][101];
int res;
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			res += 6*a[i][j]- 2*(a[i][j]-1);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i+1 <= n) res -= 2*min(a[i][j], a[i+1][j]);
			if(j+1 <= m) res -= 2*min(a[i][j], a[i][j+1]);
		}
	}
	cout << res;
}

