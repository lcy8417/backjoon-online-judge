#include <bits/stdc++.h>
using namespace std;

long long unsigned int dy[92];

int main(){
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	dy[0] = 0;
	dy[1] = 1;
	dy[2] = 1;
	for(int i = 2; i <= N; i++) dy[i] = dy[i-1] + dy[i-2];
	cout << dy[N];
}
