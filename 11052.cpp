#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int c[MAX];
int dy[MAX];
int N, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> c[i];
		dy[i] = c[i];
	}
	for(int i = 2; i <= N; i++){
		for(int j = 1; j <= i-1; j++){
			dy[i] = max(dy[i-j] + dy[j], dy[i]);
		}
	}
	cout << dy[N];
	return 0;
}
