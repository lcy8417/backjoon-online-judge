#include <bits/stdc++.h>
using namespace std;

int dy[12];

int main(){
	ios_base::sync_with_stdio(false);
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		dy[1] = 1;
		dy[2] = 2;
		dy[3] = 4;
		for(int i = 4; i <= n; i++){
			dy[i] = dy[i-1] + dy[i-2] + dy[i-3];
		}
		cout << dy[n] << "\n";
		for(int i = 4; i <= n; i++) dy[i] = 0;
	}
}
