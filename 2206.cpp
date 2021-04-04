#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define x first
#define y second
#define MAX 1001
using namespace std;

struct Loc{
	int x;
	int y;
	int cnt;
	Loc(int a, int b, int c){
		x = a;
		y = b;
		cnt = c;
	}
};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int map[MAX][MAX];
int dist[MAX][MAX][2];
int N, M, ac;
queue <Loc> q;
string text;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> text;
		for(int j = 0; j < M; j++){
			map[i][j+1] = text[j] - '0';
		}
	}
	if(N == 1 && M == 1){
		cout << 1;
		return 0;
	}
	q.push(Loc(1, 1, 0));
	dist[1][1][0] = 1;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		for(int k = 0; k < 4; k++){
			int xx = x + dx[k];
			int yy = y + dy[k];
			if(xx < 1 || yy < 1 || xx > N || yy > M || (map[xx][yy] && cnt)) continue;
			if(map[xx][yy]){
				if(dist[xx][yy][cnt+1]) continue;
				q.push(Loc(xx, yy, cnt+1)); 
				dist[xx][yy][cnt+1] = dist[x][y][cnt]+1;
				ac = dist[xx][yy][cnt+1];
			}
			else {
				if(dist[xx][yy][cnt]) continue;
				q.push(Loc(xx, yy, cnt));
				dist[xx][yy][cnt] = dist[x][y][cnt]+1;
				ac = dist[xx][yy][cnt];
			}
			
			if(xx == N && yy == M){
				cout << ac;
				return 0;
			}
		}
	}
	cout << -1;
}
