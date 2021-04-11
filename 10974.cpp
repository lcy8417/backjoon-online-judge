#include <bits/stdc++.h>

using namespace std;

int N;
int a[9];
bool visited[9];

void DFS(int L){
	if(L == N){
		for(int i = 1; i <= N; i++) cout << a[i] << " ";
		cout << "\n";
	}else{
		for(int i = 1; i <= N; i++){
			if(!visited[i]){
				visited[i] = true;
				a[L+1] = i;
				DFS(L+1);
				visited[i] = false;
			}
		}
	}
}

int main(){
	cin >> N;
	DFS(0);
}
