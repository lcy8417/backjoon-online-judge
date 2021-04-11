#include <bits/stdc++.h>
#define MAX 1000001
#define INF 2147000000
using namespace std;

int N, m;
int res = INF;
bool visited[11];
int W[11][11];

void DFS(int L, int sum, int s){
	if(L == N){
		if(s == 1) res = min(sum, res);
	}else{
		for(int i = 1; i <= N; i++){
			if(!W[s][i]) continue;
			if(!visited[i]){
				visited[i] = true;
				DFS(L+1, sum + W[s][i], i);
				visited[i] = false;
			}
		}
	}
}

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> W[i][j];
		}
	}
	DFS(0, 0, 1);
	if(res == INF) cout << 0;
	else cout << res;
}
