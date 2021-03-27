#include <bits/stdc++.h>
using namespace std;

int a[1001];
vector <int> dy(1001, 1);
int n, res = 1;

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n-1; i++){
		for(int j = i+1; j <= n; j++){
			if(a[i] < a[j]){			
				dy[j] = max(dy[j], dy[i] + 1);
				res = max(dy[j], res);
			}
		}
	}
	cout << res;
}


