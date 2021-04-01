#include <bits/stdc++.h>
#define FALSE -9999
using namespace std;

int p[3001][3001];
int res[3];
void DFS(int x, int y, int len){
	if(len == 1) {
		if(p[x][y] == -1) res[0]++;
		else if(p[x][y] == 0) res[1]++;
		else if(p[x][y] == 1) res[2]++;
		return;
	}
	int check = p[x][y];
	for(int i = x; i < x+len; i++){
		for(int j = y; j < y+len; j++){
			if(check != p[i][j]) {
				check = FALSE;
				break;
			}
		}
	}
	if(check == -1) res[0]++;
	else if(check == 0) res[1]++;
	else if(check == 1) res[2]++;
	else{
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++)
				DFS(x+i*(len/3), y+j*(len/3), len/3);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++) cin >> p[i][j];
	DFS(1, 1, N);
	cout << res[0] << "\n" << res[1] << "\n" << res[2];
}
