#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int n, m;

int work[21];

int main() {
	ios_base::sync_with_stdio(false);
	vector <int> v[21];
	queue <int> q;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		work[b]++;
		v[a].push_back(b);
	}
	for(int i = 1; i <= n; i++){
		if(work[i] == 0) q.push(i);
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x << " ";
		for(int i = 0; i < v[x].size(); i++){
			int temp = v[x][i];
			work[temp]--;
			if(work[temp] == 0) q.push(temp);
		}
	}
}
