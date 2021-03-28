#include <bits/stdc++.h>
using namespace std;

int dy[100001];
int a[100001];

int main(){
	ios::sync_with_stdio(false);
	int n, res = -1001;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		if(i >= 2 && a[i-1] < 0){
			dy[i] = max(a[i], a[i] + a[i-1] + dy[i-2]);
		}else{
			dy[i] = a[i] + dy[i-1];
		}
		res = max(res, dy[i]);
	}
	cout << res;
}
