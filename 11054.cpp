#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n, res = 1;
	cin >> n;
	vector <int> a(n+1, 0);
	vector <int> fdp(n+1, 1);
	vector <int> bdp(n+1, 0);
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
			if(a[i] < a[j]) fdp[j] = max(fdp[j], fdp[i]+1);
	
	
	for(int i = n; i >= 2; i--)
		for(int j = i-1; j >= 1; j--)
			if(a[i] < a[j]) bdp[j] = max(bdp[j], bdp[i]+1);
	
	for(int i = 1; i <= n; i++) res = max(res, fdp[i] + bdp[i]);
	cout << res;
}
