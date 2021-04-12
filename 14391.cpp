#include <bits/stdc++.h> 

using namespace std;

int n, m, res;
string s;
int p[4][4];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++)
		p[i][j] = s[j] - '0';
	}
	// 행 : 1 | / 열 : 0 - 
	for(int k = 0; k < (1 << n*m); k++){
		int sum = 0;
		for(int i = 0; i < n; i++){
			int cur = 0;
			for(int j = 0; j < m; j++){
				int s = i*m+j;
				if((k&(1<<s)) != 0){
					cur = cur * 10 + p[i][j];
				}else{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur; // 마지막 행 까지 간 경우 
		}
		for(int j = 0; j < m; j++){
			int cur = 0;
			for(int i = 0; i < n; i++){
				int s = i*m+j;
				if((k&(1<<s)) == 0){
					cur = cur * 10 + p[i][j];
				}else{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur; // 마지막 열 까지 간 경 우 
		}
		res = max(sum, res);
	}
	cout << res;
}
