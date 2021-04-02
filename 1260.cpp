#define x first
#define y second
#include <bits/stdc++.h>
using namespace std;

int N, M, V, a, b;
vector <int> v[1001];
int ch[1001];
queue <int> q;

bool compare(vector <int> a, vector <int> b){
	return a < b;
}

void DFS(int L, int s){
	if(L == N){
		return;
	}else{
		for(int j = 0; j < v[s].size(); j++){
			if(ch[v[s][j]] == 0){
				ch[v[s][j]] = 1;
				cout << v[s][j] << " ";
				DFS(L+1, v[s][j]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> V;
	for(int i = 1; i <= M; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= N; i++) sort(v[i].begin(), v[i].end());
	ch[V] = 1;
	cout << V << " ";
	DFS(1, V);
	cout << "\n";
	
	for(int i = 1; i <= N; i++) ch[i] = 0;
	q.push(V);
	ch[V] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x << " ";
		for(int i = 0; i < v[x].size(); i++){
			if(ch[v[x][i]] == 0){
				ch[v[x][i]] = 1;
				q.push(v[x][i]);
			}
		}
	}
	cout << "\n";
}
