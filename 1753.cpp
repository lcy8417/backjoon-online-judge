#include <iostream>
#include <queue>
#include <vector>
#define MAX 20001 
using namespace std;

struct Loc{
	int x;
	int cost;
	Loc(int a, int b){
		x = a;
		cost = b;
	}
	bool operator<(const Loc &b) const{
		return cost > b.cost;
	}
};

int dist[MAX];
bool visited[MAX];
vector <pair<int, int> > map[MAX];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	priority_queue <Loc> q;
	int V, E, n, m, c, start;
	cin >> V >> E >> start;
	while (E--){
		cin >> n >> m >> c;
		map[n].push_back(make_pair(m, c));
	}
	for (int i = 0; i <= V; i++) dist[i] = 2147000000;
	dist[start] = 0;
	q.push(Loc(start, 0));
	while(!q.empty()){
		int v = q.top().x;
		int cost = q.top().cost;
		q.pop();
		/*if (visited[v])  continue;
		visited[v] = true;*/
		for (int j = 0; j < map[v].size(); j++){
			int nv = map[v][j].first;
			int ncost = map[v][j].second;
			if (dist[nv] > cost + ncost){
				dist[nv] = cost + ncost;
				q.push(Loc(nv, dist[nv]));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == 2147000000) cout << "INF \n";
		else cout << dist[i] << "\n";
	}
}
