#include <bits/stdc++.h>
using namespace std;

int a[1001];
vector <int> dy(1001, 1);

int main(){
	ios_base::sync_with_stdio(false);
	int n, res=1;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(a[i] > a[j])
				dy[j] = max(dy[j], dy[i]+1);
			res = max(dy[j], res);
		}
	}
	cout << res;
}
