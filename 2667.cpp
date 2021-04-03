#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool visit[26][26];
int house[26][26];
vector <int> v;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	queue <pair<int, int> > q;
	int N;
	string s;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> s;
		for(int j = 0; j < N; j++) {
			house[i][j+1] = s[j] - '0';
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(!visit[i][j] && house[i][j]){
				int cnt = 0;
				q.push(make_pair(i, j));
				visit[i][j] = true;
				res++;
				cnt++;
				while(!q.empty()){
					int x = q.front().x;
					int y = q.front().y;
					q.pop();
					for(int i = 0; i < 4; i++){
						int xx = x+dx[i];
						int yy = y+dy[i];
						if(xx < 1 || yy < 1 || xx > N || yy > N || visit[xx][yy] || !house[xx][yy]) continue;
						q.push(make_pair(xx, yy));
						visit[xx][yy] = true;
						cnt++;
					}
				}
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << res << "\n";
	for(int i = 0; i < v.size(); i++) cout << v[i] << "\n";
}
