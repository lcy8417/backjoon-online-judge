#include <bits/stdc++.h>

using namespace std;

long long int edge[100001];
long long int ver[100001];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	long long int res = 0;
	cin >> n;
	for(int i = 1; i <= n-1; i++) cin >> edge[i];
	for(int i = 1; i <= n; i++) {
		cin >> ver[i];
		if(i != n){
			if(i >= 2 && ver[i] > ver[i-1]) ver[i] = ver[i-1];
		 	res += edge[i] * ver[i];
		}
	}
	cout << res;
	return 0;
}
