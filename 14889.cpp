#include <bits/stdc++.h>

using namespace std;

int sc[21][21];
int res = 9999, n;
int ch[21];

void DFS(int L, int s){
	if(L >= n / 2){
		int start_sum = 0;
		int link_sum =0;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
				if(ch[i] == 1 && ch[j] == 1) start_sum += sc[i][j];
				if(ch[i] == 0 && ch[j] == 0) link_sum += sc[i][j];
			}
		}
		res = min(res, abs(start_sum - link_sum));
		return;
	}
	else{
		for(int i = s; i <= n; i++){
			if(ch[i] == 0){
				ch[i] = 1;
				DFS(L+1, i+1);
				ch[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) cin >> sc[i][j];
	}
	DFS(0, 1);
	cout << res;
	return 0;
}


