#include <bits/stdc++.h>

using namespace std;

int n, m;
int dy[10];

void DFS(int L, int s){
	if(L == m){
		for(int i = 0; i < m; i++)
			cout << dy[i] << " ";
		cout << "\n";
	}else{
		for(int i = s; i <= n; i++){
			dy[L] = i;
			DFS(L+1, dy[L]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	DFS(0, 1);
	return 0;
}
