#include <bits/stdc++.h>

using namespace std;

int res, N, a, b;
int dy[16];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	vector <pair<int, int> > sc(N+1, make_pair(0, 0));
	for(int i = 1; i <= N; i++) {
		cin >> a >> b;
		sc[i].first = a;
		sc[i].second = b;
	}
	for(int i = 1; i <= N; i++){
		int next1 = i + sc[i].first;
		int next2 = i + 1;
		if(next1 <= N + 1) dy[next1] = max(dy[next1], dy[i]+sc[i].second);
		if(next2 <= N + 1) dy[next2] = max(dy[next2], dy[i]);
		res = max(max(res, dy[next1]), dy[next2]);
	}
	cout << res;
	return 0;
}
