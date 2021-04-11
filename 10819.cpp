#include <bits/stdc++.h>

using namespace std;

int N;
int res;
int a[9];
int b[9];
bool visited[9];

void DFS(int L){
	if(L == N){
		
		int sum = 0;
		for(int i = 2; i <= N; i++){
			sum += abs(b[i-1]-b[i]);
		}
		res = max(res, sum);
	}else{
		for(int i = 1; i <= N; i++){
			if(!visited[i]){
				visited[i] = true;
				b[L+1] = a[i];
				DFS(L+1);
				visited[i] = false;
			}
		}
	}
}

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	DFS(0);
	cout << res;
}
