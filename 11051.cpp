#include <bits/stdc++.h>
using namespace std;

long long int dy[1001][1001];

int DFS(int n, int k){
	if(dy[n][k] != 0) return dy[n][k];
	if(n == k) return 1;
	if(k == 0) return 1;
	else return dy[n][k] = (DFS(n-1, k-1) % 10007 + DFS(n-1, k) % 10007) % 10007;
}

int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	cout << DFS(n, k);
}	
