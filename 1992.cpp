#include <bits/stdc++.h>

using namespace std;

char tree[65][65];

void DFS(int x, int y, int len){
	char check = tree[x][y];
	for(int i = x; i < x+len; i++){
		for(int j = y; j < y+len; j++){
			if(tree[i][j] != check){
				check = '2';
				break;
			}
		}
	}
	if(check == '0'){
		cout << 0;
	}else if(check == '1'){
		cout << 1;	
	}else{
		cout << "(";
		DFS(x, y, len/2);
		DFS(x, y+len/2, len/2);
		DFS(x+len/2, y, len/2);
		DFS(x+len/2, y+len/2, len/2);
		cout << ")";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int N;
	string pic;
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> pic;
		for(int j = 1; j <= N; j++)
			tree[i][j] = pic[j-1];
	}
	
	DFS(1, 1, N);
}
