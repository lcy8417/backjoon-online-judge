#include <bits/stdc++.h>

using namespace std;

int res, N, a, b;
vector <pair<int, int> > sc;
void DFS(int s, int sum){
	if(s > N) return;
	if(s >= N){
		res = max(res, sum);
	}else{
		for(int i = s; i <= N; i++){
			DFS(i+sc[i].first, sum+sc[i].second);
			res = max(res, sum);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> a >> b;
		sc.push_back(make_pair(a, b));
	}
	DFS(0, 0);
	cout << res;
	return 0;
}
