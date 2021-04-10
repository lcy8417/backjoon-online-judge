#include <bits/stdc++.h>

using namespace std;

struct Pos{
	int x;
	int y;
	Pos(int a, int b){
		x = a;
		y = b;
	}
};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int N, M, K, ans = -2147000000;
int a[11][11];
bool visited[11][11];
vector <Pos> pos[11][11]; 

void check(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > N || ny > M || visited[nx][ny]) continue;
		visited[nx][ny] = true;
		pos[x][y].push_back(Pos(nx, ny));
	}
}

void DFS(int cnt, int sum, int s1, int s2){
	if(cnt == K){
		ans = max(sum, ans);
	}else{
		for(int i = s1; i <= N; i++){
			for(int j = s2; j <= M; j++){
				if(!visited[i][j]){
					visited[i][j] = true;
					check(i, j);
					DFS(cnt+1, sum + a[i][j], 1, j);
					visited[i][j] = false;
					for(int k = 0; k < pos[i][j].size(); k++) visited[pos[i][j][k].x][pos[i][j][k].y] = false; // 현재 버텍스에서 방문한곳 초기화 
					pos[i][j].clear(); // 초기화후 클리어 
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) cin >> a[i][j];
	DFS(0, 0, 1, 1);
	cout << ans;
}
