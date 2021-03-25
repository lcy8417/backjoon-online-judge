#include <bits/stdc++.h>
using namespace std;

int dy[301];
int st[301];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> m;
		st[i] = m;
	}
	dy[1] = st[1];
	dy[2] = st[1] + st[2];
	dy[3] = max(st[1] + st[3], st[2] + st[3]);
	
	for(int i = 4; i <= n; i++){
		dy[i] = max(dy[i-3] + st[i-1] + st[i], dy[i-2] + st[i]);
	}
	cout << dy[n];
}
