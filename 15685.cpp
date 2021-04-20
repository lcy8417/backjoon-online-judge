#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, x, y, d, g, res;
bool ch[101][101];
vector <pair<int, int> > v[21];
int gen[21];

void Turn(int dir, int i, int a, int b){
	switch(dir){
		case 0:
			if(a+1 <= 100) {
				v[i].push_back(make_pair(a+1, b));
				ch[a+1][b] = true;
			}
			break;
		case 1:
			if(b-1 >= 0) {
				v[i].push_back(make_pair(a, b-1));
				ch[a][b-1] = true;
			}
			break;
		case 2:
			if(a-1 >= 0){
				v[i].push_back(make_pair(a-1, b));
				ch[a-1][b] = true;
			} 
			break;
		case 3:
			if(b+1 <= 100) {
				v[i].push_back(make_pair(a, b+1));
				ch[a][b+1] = true;
			}
			break;
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> d >> g;
		v[i].push_back(make_pair(x, y));
		ch[x][y] = true;
		gen[i] = g;
		Turn(d, i, x, y);
	}
	//for(int i = 0; i < v[2].size(); i++) cout << v[2][i].first << " " << v[2][i].second << " ";
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= gen[i]; j++){
			int len = v[i].size();
			for(int k = len-1; k >= 1; k--){ // 온방향 확인 
				int nx = v[i][v[i].size()-1].first;
				int ny = v[i][v[i].size()-1].second;
				int lx = v[i][k].first - v[i][k-1].first;
				int ly = v[i][k].second - v[i][k-1].second;
				if(lx==0 && ly==1){ //밑으로 왔을 때 
					Turn(0, i, nx, ny); 
				}else if(lx==0 && ly==-1){ // 위로 왔을 떄 
					Turn(2, i, nx, ny);
				}else if(lx==1 && ly == 0){ // 오른쪽으로 왔을떄 
					Turn(1, i, nx, ny);
				}else{ // 왼쪽으로 왔을 때 
					Turn(3, i, nx, ny);
				}
			}
		}
	}
	for(int i = 0; i <= 99; i++){
		for(int j = 0; j <= 99; j++){
			if(ch[i][j] && ch[i+1][j] && ch[i][j+1] && ch[i+1][j+1]) res++;
		}
	}
	cout << res;
}
