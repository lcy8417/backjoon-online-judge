#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b){
	if(b==0) return a;
	else return GCD(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		vector <int> v(n+1, 0);
		int sum = 0;
		for(int i = 1; i <= n; i++) cin >> v[i];
		sort(v.begin()+1, v.end());
		for(int i = 1; i <= n-1; i++){
			for(int j = i+1; j <= n; j++){
				sum += GCD(v[i], v[j]);
			}
		}
		if(!sum) cout << v[1] << "\n";
		else cout << sum << "\n";
	}
	return 0;
}
