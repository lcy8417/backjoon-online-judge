#include <bits/stdc++.h>

using namespace std;

long long unsigned int dy[91];

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	dy[1] = 1;
	dy[2] = 1;
	for(int i = 3; i <= N; i++){
		dy[i] = dy[i-1]*2 - dy[i-3];
	}
	cout << dy[N];
	return 0;
}
