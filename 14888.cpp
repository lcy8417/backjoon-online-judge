#include <bits/stdc++.h>

using namespace std;

int op[4];
int n;
vector <int> v(12);
int maxi = -1000000001;
int mini = 1000000001;
void DFS(int L, int sum){
	if(L == n){
		maxi = max(sum, maxi);
		mini = min(sum, mini);
	}else{
		for(int i = 0; i < 4; i++){
			if(op[i] > 0){
				if(i == 0){
					op[0]--;
					DFS(L+1, sum + v[L+1]);
					op[0]++;
				}if(i == 1){
					op[1]--;
					DFS(L+1, sum - v[L+1]);
					op[1]++;
				}if(i == 2){
					op[2]--;
					DFS(L+1, sum * v[L+1]);
					op[2]++;
				}if(i == 3){
					op[3]--;
					DFS(L+1, sum / v[L+1]);
					op[3]++;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		v[i] = m;
	}
	for(int i = 0; i < 4; i++){
		cin >> op[i];
	}
	DFS(1, v[1]);
	cout << maxi << "\n" << mini;
	return 0;
}
