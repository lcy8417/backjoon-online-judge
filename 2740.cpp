#include <bits/stdc++.h>
using namespace std;

int a[101][101];
int b[101][101];
int c[101][101];

int main(){
	ios_base::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++) cin >> a[i][j];
	}
	cin >> M >> K;
	for(int i = 1; i <= M; i++){
		for(int j = 1; j <= K; j++) cin >> b[i][j];
	}
	for(int k = 1; k <= M; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= K; j++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){
			cout << c[i][j] << " ";
		}
		cout << "\n";
	}
}
