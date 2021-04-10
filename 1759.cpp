#include <bits/stdc++.h>

using namespace std;

int L, C;
char pass[16];
char ans[16];

void DFS(int len, int cons, int coll, int s){
	if(len > L) return;
	if(len == L){
		if(cons >= 1 && coll >= 2){
			for(int i = 0; i < L; i++) cout << ans[i];
			cout << "\n";
		}
	}else{
		for(int i = s; i <= C; i++){
			ans[len] = pass[i];
			if(pass[i] == 'a' || pass[i] == 'e' || pass[i] == 'i' || pass[i] == 'o' || pass[i] == 'u') DFS(len+1, cons+1, coll, i+1);
			else DFS(len+1, cons, coll+1, i+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> L >> C;
	for(int i = 1; i <= C; i++) cin >> pass[i];
	sort(pass+1, pass+1+C);
	DFS(0, 0, 0, 1);
}
