#include <bits/stdc++.h>
using namespace std;

int a, b;
int dy[31][31];


int DFS(int i, int j){
	if(dy[i][j]) return dy[i][j];
	if(i == j || j == 0) return 1;
	else return dy[i][j] = DFS(i-1, j-1) + DFS(i-1, j);
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		cout << DFS(b, a) << "\n";
	}
	
}	
