#include <bits/stdc++.h>

using namespace std;

int N, res;
string s;
char candy[51][51];

void searchCandy(){
	for(int i = 1; i <= N; i++){ // 행기준 
		for(int j = 1; j <= N-1; j++){
			int cnt = 1;
			for(int k = j+1; k <= N; k++){
				if(candy[i][k-1] == candy[i][k]) cnt++;
				else break;
			}
			res = max(cnt, res);
		}
	}
	
	for(int i = 1; i <= N; i++){ // 열기준 
		for(int j = 1; j <= N-1; j++){
			int cnt = 1;
			for(int k = j+1; k <= N; k++){
				if(candy[k-1][i] == candy[k][i]) cnt++;
				else break;
			}
			res = max(cnt, res);
		}
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> s;
		for(int j = 0; j < N; j++){
			candy[i][j+1] = s[j];
		}
	}

	for(int i = 1; i <= N; i++){ //행기준 
		for(int j = 2; j <= N-1; j++){
			if(candy[i][j] != candy[i][j-1]) swap(candy[i][j], candy[i][j-1]);
			searchCandy();
			if(candy[i][j] != candy[i][j-1]) swap(candy[i][j], candy[i][j-1]); // 원상복구 
		}
	}
	
	for(int i = 1; i <= N; i++){ //열기준 
		for(int j = 2; j <= N; j++){
			if(candy[j][i] != candy[j-1][i]) swap(candy[j][i], candy[j-1][i]);
			searchCandy();
			if(candy[j][i] != candy[j-1][i]) swap(candy[j][i], candy[j-1][i]); // 원상복구 
		} 
	}
	cout << res; 
	return 0;
}
