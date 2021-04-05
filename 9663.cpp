#include <bits/stdc++.h>
using namespace std;

int queen[16];
int ac;
int N;

void DFS(int L){
	if(L == N) ac++;
	else{
		for(int i = 0; i < N; i++){
			queen[L] = i;
			bool impossible = false;
			for(int j = 0 ; j < L; j++){
				if(queen[j] == queen[L] || abs(j-L) == abs(queen[j]-queen[L]))
					impossible = true;
			}
			if(!impossible) DFS(L+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	DFS(0);
	cout << ac;
}
