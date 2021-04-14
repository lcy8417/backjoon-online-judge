#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

vector <long long> dy(1000001, 0);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		dy[1] = 1;
		dy[2] = 2;
		dy[3] = 4;
		for(int i = 4; i <= n; i++)
			dy[i] = dy[i-1]%MOD + dy[i-2]%MOD + dy[i-3]%MOD;
		cout << dy[n] << "\n";
	}
}
