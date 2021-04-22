#include <iostream>

using namespace std;

int a[301][301];
int b[601][601];

int main(){
	ios_base::sync_with_stdio(false);
	int H, W, X, Y;
	cin >> H >> W >> X >> Y;
	int dx = H-X-1; // 겹치는 부분 행 길이 
	int dy = W-Y-1; // 겹치는 부분 열 길이 
	for(int i = 1; i <= H+X; i++){
		for(int j = 1; j <= W+Y; j++){
			cin >> b[i][j];
		}
	}
	for(int i = X+1; i <= X+1+dx; i++){ // 겹치는 부분 
		for(int j = Y+1; j <= Y+1+dy; j++){
			b[i][j] -= b[i-X][j-Y]; 
		}
	}
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			cout << b[i][j] << " ";
		}
		cout << "\n";
	}
}
