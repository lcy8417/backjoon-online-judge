#include <bits/stdc++.h>

using namespace std;

int cp[129][129];
int c[2];

void DFS(int x, int y, int n){
	int color = cp[x][y];
	for(int i = x; i < x + n; i++){
		for(int j = y; j < y + n; j++){
			if(cp[i][j] != color){
				color = -1;
				break;
			}
		}
	}
	if(color == 1){
		c[1]++;
	}else if(color == 0){
		c[0]++;
	}else{
		DFS(x, y, n/2);
		DFS(x, y+n/2, n/2);
		DFS(x+n/2, y, n/2);
		DFS(x+n/2, y+n/2, n/2);
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> cp[i][j];
		}
	}
	DFS(1, 1, N);
	cout << c[0] << "\n" << c[1];
}
