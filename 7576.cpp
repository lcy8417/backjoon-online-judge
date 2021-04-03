#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int M, N, a, res;
queue <pair<int, int> > q;
int map[1001][1001];
int time[1001][1001];
bool impossible = false;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> M >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> a;
			map[i][j] = a;
			if(a == 1) q.push(make_pair(i, j));
		}
	}
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx < 1 || yy < 1 || xx > N || yy > M || map[xx][yy]) continue;
			time[xx][yy] = time[x][y] + 1;
			res = max(time[xx][yy], res);
			map[xx][yy] = 1;
			q.push(make_pair(xx, yy));
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(map[i][j] == 0) {
				cout << impossible << "\n";
				impossible = !impossible;
				cout << impossible << "\n";
				break;
			}
		}
	}
	if(impossible) cout << -1;
	else cout << res;
}
