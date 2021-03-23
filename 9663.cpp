#include <bits/stdc++.h>

using namespace std;


int cs[16];
int cnt, n;

void DFS(int L){
	if(L == n){
		cnt++;
		return;
	}else{
		for(int i = 1; i <= n; i++){
			bool flag = true;
			for(int j = 0; j < L; j++){
				if(cs[j] == i || abs(L - j) == abs(cs[j] - i)){
					flag = false;
					break;
				}
			}
			if(flag) {
				cs[L] = i;
				DFS(L+1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	DFS(0);
	cout << cnt;
	return 0;
}
