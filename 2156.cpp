#include <bits/stdc++.h>
using namespace std;

int n, res;
int dy[10001];
int grape[10001];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> grape[i];
	
	dy[1] = grape[1];
	dy[2] = grape[1] + grape[2];
	for(int x =3; x <= n; x++){
		dy[x] = max(dy[x-2]+grape[x], dy[x-3]+grape[x-1]+grape[x]);
		dy[x] = max(dy[x-1], dy[x]);
		res = max(dy[x], res);
	}
	if(n == 1) cout << dy[1];
	else if(n == 2) cout << dy[2];
	else cout << res;
}
