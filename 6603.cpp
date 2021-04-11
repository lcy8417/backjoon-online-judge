#include <bits/stdc++.h>

using namespace std;

int lotto[14];
int ouput[14];
bool visited[14];
int N;

void DFS(int L, int s){
	if(L == 6){
		for(int i = 1; i <= 6; i++) cout << ouput[i] << " ";
		cout << "\n";
	}else{
		for(int i = s; i <= N; i++){
			if(!visited[i]){
				visited[i] = true;
				ouput[L+1] = lotto[i];
				DFS(L+1, i+1);
				visited[i] = false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	while(1){
		cin >> N;
		if(N == 0) break;
		for(int i = 1; i <= N; i++) cin >> lotto[i];
		DFS(0, 1);
		cout << "\n";
		for(int i = 1; i <= N; i++) {	
			visited[i] = false;
			lotto[i] = 0;
			ouput[i] = 0;
		}
	}
}
