#include <bits/stdc++.h>
using namespace std;

int v[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	int n, mini = 1000001, maxi = -1000001;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		maxi = max(maxi, v[i]);
		mini = min(mini, v[i]);
	}
	cout << mini << " " << maxi;
}
