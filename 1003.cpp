#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int> > dy(41, make_pair(0, 0));

void fibonacci(int n){
	if(dy[n].first >= 1 || dy[n].second >= 1) return;
	if(n == 0){
		dy[0].first = 1;
		return;
	}else if(n == 1){
		dy[1].second = 1;
		return;
	}else{
		fibonacci(n-1);
		fibonacci(n-2);
		dy[n].first = dy[n-1].first + dy[n-2].first;
		dy[n].second = dy[n-1].second + dy[n-2].second;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> m;
		fibonacci(m);
		cout << dy[m].first << " " << dy[m].second << "\n";
		for(int j = 0; j <= m; j++) {
			dy[j].first = 0; dy[j].second = 0;
		}
	}
}


