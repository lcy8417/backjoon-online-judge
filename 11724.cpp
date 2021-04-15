#include <iostream>
#include <vector>
using namespace std;

vector <int> v[1001];
bool ch[1001];
int n, m, a, b, res;

void DFS(int s){
	for(int i = 0; i < v[s].size(); i++){
		int next = v[s][i];
		if(!ch[next]){
			ch[next] = true;
			DFS(next);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		if(!ch[i]){
			res++;
			ch[i] = true;
			DFS(i);
		}
	}
	cout << res;
}
