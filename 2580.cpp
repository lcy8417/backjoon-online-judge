#include <bits/stdc++.h>

using namespace std;

int sdoque[10][10];
int ch[10];

void square(int x, int y){ // 3 x 3 �簢���� ���������� üũ 
	int row = x / 3 * 3;
	int col = y / 3 * 3; 
	for(int i = row; i <= row + 2; i++){
		for(int j = col; j <= col + 2; j++)
			ch[sdoque[i][j]] = 1;
	}
}

void rowCol(int x, int y){  // ����� �� üũ 
	for(int i = 0; i < 9; i++){
		ch[sdoque[x][i]] = 1;
		ch[sdoque[i][y]] = 1;
	}
}

bool isNum(int x){ // ���� �� á���� ���� ������ 
	for(int i = 0; i < 9; i++) if(sdoque[x][i] == 0) return false; // ���߿� ���� ������ false
	return true;
}

void DFS(int L){
	if(L == 1) {
		cout << "\n";
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++)
				cout << sdoque[i][j] << " ";
			cout << "\n";
		}
		exit(0);
	}else{
		for(int i = 0; i < 9; i++){
			if(sdoque[L][i] == 0){
				//cout << L << " " << i << endl;
				square(L, i);
				rowCol(L, i);
				for(int j = 1; j <= 9; j++) {
					if(ch[j] == 0) {
						//cout << ch[j] << endl;
						sdoque[L][i] = j;
						ch[j] = 1;
						if(isNum(L)) {
						for(int j = 1; j <= 9; j++) ch[j] = 0;
						DFS(L+1);
					}else{
						DFS(L);
						sdoque[L][i] = 0;
						ch[sdoque[L][i]] = 0;
						}	
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
		
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> sdoque[i][j];
		}
	}
	DFS(0);
	
	
	
	return 0;
}
