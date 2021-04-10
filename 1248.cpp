#include <bits/stdc++.h>

using namespace std;

int N;
char S[11][11];
int A[11];

void DFS(int L, int sum){
	if(L == N){
		for(int i = 1; i <= N; i++) cout << A[i] << " ";
		exit(0);
	}else{
		for(int k = -10; k <= 10; k++){
			A[L+1] = k;
			bool flag = false;
			for(int i = 1; i <= L+1; i++){
				int temp = 0;
				for(int j = i; j <= L+1; j++){
					temp += A[j];
					if(S[i][j] == '+'){
						if(temp <= 0) {
							flag = true;
							break;
						}
					}else if(S[i][j] == '-'){
						if(temp >= 0){
							flag = true;
							break;
						}
					}else{
						if(temp != 0) {
							flag = true;
							break;
						}
					}
				}
				if(flag) break;
			}
			if(!flag){
				DFS(L+1, sum + k);
				flag = false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	string op;
	int p = -1;
	cin >> op;
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j++){
			S[i][j] = op[++p];
		}
	}
	DFS(0, 0);
}
