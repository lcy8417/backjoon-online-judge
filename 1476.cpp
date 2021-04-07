#include <bits/stdc++.h>

using namespace std;

int E, S, M, cnt=1;

void DFS(int e, int s, int m){
	if(e > 15) e = 1;
	if(s > 28) s = 1;
	if(m > 19) m = 1;
	if(E == e && s == S && m == M){
		cout << cnt;
		exit(0);
	}
	cnt++;
	DFS(e+1, s+1, m+1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> E >> S >> M;
	DFS(1, 1, 1);
}
