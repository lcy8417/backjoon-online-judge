#include <iostream>
#include <queue>
#include <vector>
#define MAX 20001
#define RED 1
#define BLUE 2
using namespace std;

int visited[MAX];
vector <int> map[MAX];
queue <int> q;
int T, V, E, n, m;

//void DFS(int s){
//	
//	
//	for(int i = 0; i < map[s].size(); i++){
//		int next = map[s][i];
//		if(!visited[next]){
//			if(visited[s] == RED) visited[next] = BLUE;
//			else if(visited[s] == BLUE) visited[next] = RED;
//			DFS(next);
//		}
//	}
//}

void BFS(int s){
	q.push(s);
	while(!q.empty()){
		int start = q.front();
		q.pop();
		for(int i = 0; i < map[start].size(); i++){
			int next = map[start][i];
			if(!visited[next]){
				if(visited[start] == RED){
					visited[next] = BLUE;
				}else if(visited[start] == BLUE){
					visited[next] = RED;
				}
				q.push(next);
			}
		}
	}
}

bool isGraph(){
	for(int i = 1; i <= V; i++){
		for(int j = 0; j < map[i].size(); j++){
			if(visited[i] == visited[map[i][j]]) return 0;
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--){
		cin >> V >> E;
		for(int i = 1; i <= E; i++){
			cin >> n >> m;
			map[n].push_back(m);
			map[m].push_back(n); 
		}
		for(int i = 1; i <= V; i++){
			if(!visited[i]){
				visited[i] = RED;
				//DFS(i);
				BFS(i);
			}
		}
		if(isGraph()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		
		for(int i = 1; i <= V; i++) visited[i] = 0;
		for(int i = 1; i <= V; i++){
			map[i].clear();
		}
	}
}
