#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


struct Tom{
	int x;
	int y;
	int h;
	Tom(int a, int b,int c){
		x = a;
		y = b;
		h = c;
	}
};

using namespace std;
int dx[] = {0, 1, 0, -1, 0, 0};
int dy[] = {1, 0, -1, 0, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};
int M, N, H, res=1;
queue <Tom> q;
int map[101][101][101];
bool impossible = false;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> M >> N >> H;
	for(int k = 1; k <= H; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				cin >> map[i][j][k];
				if(map[i][j][k] == 1) q.push(Tom(i, j, k));
			}
		}
	}
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int h = q.front().h;
		q.pop();
		for(int i = 0; i < 6; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			int hh = h + dh[i];
			if(xx < 1 || yy < 1 || xx > N || yy > M || hh < 1 || hh > H || map[xx][yy][hh]) continue;
			map[xx][yy][hh] =  map[x][y][h] + 1;
			res = max(res, map[xx][yy][hh]);
			q.push(Tom(xx, yy, hh));
		}
	}
	for(int k = 1; k <= H; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				if(map[i][j][k] == 0) {
					impossible = true;
					break;
				}
			}
		}
	}
	
	if(impossible) cout << -1;
	else cout << res-1;
}
