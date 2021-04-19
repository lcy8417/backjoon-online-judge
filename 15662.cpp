#include <iostream>
#include <vector>

using namespace std;

int t, k, n, r, res;
string s;
int a[1001][8];
int temp[8];
void RightRotate(int x){// 시계 
	temp[0] = a[x][7];
	for(int i = 1; i <= 7; i++) temp[i] = a[x][i-1];
	for(int i = 0; i < 8; i++) a[x][i] = temp[i];
	
} 

void LeftRotate(int x){ // 반시계 
	temp[7] = a[x][0];
	for(int i = 0; i < 7; i++) temp[i] = a[x][i+1]; 
	for(int i = 0; i < 8; i++) a[x][i] = temp[i];
}

void Rotate(int x, int c){
	vector <int> loc(1001, 0);
	loc[x] = c;
	for(int i = x; i >= 2; i--){ // 왼쪽확인 
		if(a[i-1][2] != a[i][6]) {
			if(loc[i] == 1) loc[i-1] = -1;	
			else if(loc[i] == -1) loc[i-1] = 1;
		}
	}
	for(int i = x; i <= t-1; i++){ // 오른쪽확인 
		if(a[i][2] != a[i+1][6]){
			if(loc[i] == 1) {
				loc[i+1] = -1;
			}
			else if(loc[i] == -1) loc[i+1] = 1;
		}
	}
	for(int i = 1; i <= t; i++){
		if(loc[i] == 1){
			RightRotate(i);
		}else if(loc[i] == -1){
			LeftRotate(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> s;
		for(int j = 0; j < s.length(); j++) a[i][j] = s[j] - '0';
	}
	cin >> k;
	while(k--){
		cin >> n >> r;
		Rotate(n, r);
	}
	for(int i = 1; i <= t; i++) {
		res += a[i][0];
	}
		
	cout << res;
}
