#include <bits/stdc++.h>

using namespace std;

int N, res = 2147000000;
int sc[21][21];
bool visited[21];

void DFS(int L, int s){
	if(L == N/2){
		int startTeam = 0;
		int linkTeam = 0;
		for(int i = 1; i <= N; i++){
			if(visited[i]){
				for(int j = 1; j <= N; j++){
					if(visited[j]) {
						startTeam += sc[i][j];
					}
				}
			}
		}
		for(int i = 1; i <= N; i++){
			if(!visited[i]){
				for(int j = 1; j <= N; j++){
					if(!visited[j]) {
						linkTeam += sc[i][j];
					}
				}
			}
		}
		res = min(res, abs(startTeam - linkTeam));
	}else{
		for(int i = s; i <= N; i++){
			if(!visited[i]){
				visited[i] = true;
				DFS(L+1, i+1);
				visited[i] = false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> sc[i][j];
		}
	}
	DFS(0, 1);
	cout << res;
}
