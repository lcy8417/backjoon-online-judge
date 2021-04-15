#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n, m, a, b;
vector <int> v[2001];
bool check[2001];
bool possible;
void DFS(int n, int cnt){
	if(cnt == 4){
		cout << 1;
		exit(0);
	}else{
		for(int i = 0; i < v[n].size(); i++){
			int next = v[n][i];
			if(!check[next]){
				check[next] = true;
				DFS(next, cnt+1);
				check[next] = false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 0; i < n; i++){
		check[i] = true;
		DFS(i, 0);
		check[i] = false;
	}
	cout << 0;
}
