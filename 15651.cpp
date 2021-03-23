#include <bits/stdc++.h>

using namespace std;

int n, m;
int dy[10];

void DFS(int L){
	if(L == m){
		for(int i = 0; i < m; i++)
			cout << dy[i] << " ";
		cout << "\n";
	}else{
		for(int i = 1; i <= n; i++){
			dy[L] = i;
			DFS(L+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	DFS(0);
	return 0;
}
