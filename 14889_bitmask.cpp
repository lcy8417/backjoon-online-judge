#include <bits/stdc++.h>

using namespace std;

int n, res=2147000000;
int a[21][21];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i < (1 << n); i++){
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)) cnt++;
		}
		if(cnt != n/2) continue;
		vector <int> start, second;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				start.push_back(j);
			}else{
				second.push_back(j);
			}
		}
		int fsum = 0, ssum = 0;
		for(int i = 0; i < n/2; i++){
			for(int j = 0; j < n/2; j++){
				fsum += a[start[i]][start[j]];
				ssum += a[second[i]][second[j]];
			}
		}
		res = min(res, abs(fsum-ssum));
	}
	cout << res;
}
