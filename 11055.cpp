#include <bits/stdc++.h>
using namespace std;

int a[1001];
int dy[1001];

int main(){
	ios_base::sync_with_stdio(false);
	int n, res=0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		dy[i] = a[i];
		res = max(res, dy[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(a[i] < a[j])
				dy[j] = max(dy[j], dy[i]+a[j]);
			res = max(dy[j], res);
		}
	}
	cout << res;
}
