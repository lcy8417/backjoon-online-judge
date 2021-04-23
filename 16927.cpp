#include <iostream>
#include <vector>
using namespace std;

int n, m, r;

vector<vector<int> > Rotation(vector<vector<int> > v){
	vector<vector<int> > temp(n+1,vector<int>(m+1, 0));
	int h=n, w=m, x=1;
	while(x < h && x < w){
		int cnt = r % (2*(h-x) + 2*(w-x)); 
		while(cnt--){
			for(int i = x; i < h; i++){ // step:1 아래 
				temp[i+1][x] = v[i][x];
			}
			for(int i = x; i < w; i++){ // step:2 오른쪽 
				temp[h][i+1] = v[h][i];
			}
			for(int i = h; i > x; i--){ // step:3 위로 
				temp[i-1][w] = v[i][w];
			}
			for(int i = w; i > x; i--){ // step:4 왼쪽 
				temp[x][i-1] = v[x][i];
			}
			// temp 값 다시 옮겨줘야함 v로 
			for(int i = x; i <= h; i++){ // step:1 아래 
			 	v[i][x] = temp[i][x];
			}
			for(int i = x; i <= w; i++){ // step:2 오른쪽 
				v[h][i] = temp[h][i];
			}
			for(int i = h; i >= x; i--){ // step:3 위로 
				v[i][w] = temp[i][w];
			}
			for(int i = w; i >= x; i--){ // step:4 왼쪽 
				v[x][i] = temp[x][i];
			}
		}
		x++; h--; w--; // 안으로 진입 
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			if(temp[i][j] == 0) temp[i][j] = v[i][j];
	}
	return temp;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> r;
	vector<vector<int> > a(n+1,vector<int>(m+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	a = Rotation(a);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
