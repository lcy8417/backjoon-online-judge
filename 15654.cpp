#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[10001];
vector <int> v(10001);
bool visited[10001];

void DFS(int L){
	if(L == M){
		for(int i = 0; i < M; i++) cout << v[i] << " ";
		cout << "\n";
	}else{
		for(int i = 1; i <= N; i++){
			if(!visited[i]){
				v[L] = a[i];
				visited[i] = true;
				DFS(L+1);
				visited[i] = false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a+1, a+1+N);
	DFS(0);
}
