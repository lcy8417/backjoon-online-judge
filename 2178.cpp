#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int miro[101][101];
int visited[101][101];
int N, M, res = 2147000000;
string s;
queue<pair<int, int> > q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> s;
		for(int j = 0; j < M; j++) miro[i][j+1] = s[j] - '0';
	}
	visited[1][1] = 1;
	q.push(make_pair(1, 1));
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx < 1 || yy < 1 || xx > N || yy > M || visited[xx][yy] || !miro[xx][yy]) continue;
			visited[xx][yy] = visited[x][y] + 1;
			q.push(make_pair(xx, yy));
			if(xx == N && yy == M) {
				cout << visited[xx][yy];
				exit(0);
			}
		}
	}
}
