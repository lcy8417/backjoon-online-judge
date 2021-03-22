#include <bits/stdc++.h>
using namespace std;

int arr[15][15];

int main(){
	ios_base::sync_with_stdio(false);
	int t, k, n, res;
	cin >> t;
	for(int i = 0; i <= 15; i++) arr[i][1] = 1;
	for(int i = 1; i <= t; i++){
		cin >> k >> n;
		for(int v = 0; v <= k; v++){ //Ãþ 
			for(int w = 2; w <= n; w++){ // È£¼ö 
				if(v == 0) arr[0][w] = w;
				else arr[v][w] = arr[v-1][w] + arr[v][w-1];
			}
		}
		cout << arr[k][n] << "\n";
	}
}
