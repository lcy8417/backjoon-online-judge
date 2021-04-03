#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool visit[51][51];
int veg[51][51];
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue <pair<int, int> > q;
	int T, M, N, K, a, b;
	cin >> T;
	while(T--){
		cin >> M >> N>> K;
		while(K--){
			cin >> b >> a;
			veg[a][b] = 1;
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(!visit[i][j] && veg[i][j]){
					q.push(make_pair(i, j));
					visit[i][j] = true;
					res++;
					while(!q.empty()){
						int x = q.front().x;
						int y = q.front().y;
						q.pop();
						for(int i = 0; i < 4; i++){
							int xx = x + dx[i];
							int yy = y + dy[i];
							if(xx < 0 || yy < 0 || xx >= N || yy >= M || visit[xx][yy] || !veg[xx][yy]) continue;
							q.push(make_pair(xx, yy));
							visit[xx][yy] = true;

						}
					}
				}
			}
		}
		cout << res << "\n";
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
			veg[i][j] = 0;
			visit[i][j] = false;
		}
		res = 0;
	}

}
