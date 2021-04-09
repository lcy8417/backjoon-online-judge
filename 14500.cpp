#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int N, M, res;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int t[501][501];
bool visited[501][501];

void shape1(int x, int y){ // で 
	if(y+2 > M || x+1 > N) return;
	res = max(res, t[x][y+1] + t[x+1][y] + t[x+1][y+1] + t[x+1][y+2]);
}

void shape2(int x, int y){ // ぬ 
	if(y+2 > M || x+1 > N) return;
	res = max(res, t[x][y] + t[x][y+1] + t[x][y+2] + t[x+1][y+1]);
}

void shape3(int x, int y){ // た 
	if(y+1 > M || x+2 > N) return;
	res = max(res, t[x][y] + t[x+1][y] + t[x+2][y] + t[x+1][y+1]);
}

void shape4(int x, int y){ // っ 
	if(y+1 > M || x+2 > N) return;
	res = max(res, t[x][y+1] + t[x+1][y] + t[x+1][y+1] + t[x+2][y+1]);
}

void totalSum(int x, int y){
	shape1(x, y);
	shape2(x, y);
	shape3(x, y);
	shape4(x, y);
}

void DFS(int L, int x, int y, int sum){
	if(L == 4){
		res = max(res, sum);
	}else{
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 1 || ny < 1 || nx > N || ny > M || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			DFS(L+1, nx, ny, sum + t[nx][ny]);
			visited[nx][ny] = false;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			cin >> t[i][j];
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			totalSum(i, j);
			visited[i][j] = true;
			DFS(1, i, j, t[i][j]);
			visited[i][j] = false;
		}
	}
	cout << res;
}
