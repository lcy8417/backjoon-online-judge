#include <iostream>
#include <queue>
#define MAX 300
using namespace std;

int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dist[MAX][MAX];
int res;
queue <pair<int, int> > q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, l, x, y, gox, goy;
	cin >> T;
	while(T--){
		cin >> l;
		cin >> x >> y;
		cin >> gox >> goy;
		if(x == gox && y == goy){
			cout << 0 << "\n";
			continue;
		}
		q.push(make_pair(x, y));
		while(!q.empty()){
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop();
			for(int i = 0; i < 8; i++){
				int mx = nx + dx[i];
				int my = ny + dy[i];
				if(mx < 0 || my < 0 || mx >= l || my >= l || dist[mx][my]) continue;
				dist[mx][my] = dist[nx][ny] + 1;
				q.push(make_pair(mx, my));
				if(mx == gox && my == goy){
					cout << dist[mx][my] << "\n";
					while(q.empty()) q.pop();
					break;
				}
			}
		}
		for(int i = 0; i < l; i++){ 
			for(int j = 0; j < l; j++) {
				dist[i][j] = 0;
			}
		}
		
	}
}
