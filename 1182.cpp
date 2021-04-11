#include <bits/stdc++.h>

using namespace std;

int N, S, res;
int a[21];
bool visited[21];

void DFS(int L, int sum, int s){
	if(L >= 1 && sum == S) res++;
	for(int i = s; i <= N; i++){
		DFS(L+1, sum + a[i], i+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for(int i = 1; i <= N; i++) cin >> a[i];
	DFS(0, 0, 1);
	cout << res;
}
