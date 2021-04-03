#include <bits/stdc++.h>

using namespace std;

int N, M, a, b;
vector <int> v[101];
int visit[101];
int cnt;

void DFS(int x){
	visit[x] = 1;
	cnt++;
	for(int i = 0; i < v[x].size(); i++){
		int xx = v[x][i];
		if(visit[xx] == 0){
			visit[xx] = 1;
			DFS(xx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i = 1; i <= M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	DFS(1);
	cout << cnt-1;
	return 0;
}
