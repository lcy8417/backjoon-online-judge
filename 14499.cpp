#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k, c;
int map[20][20];
 // ¡÷ªÁ¿ß 1 : ≥≤ |  2 : ¿ß |  3 : ∫œ | 4 : πÿ | 5 : µø | 6 : º≠ 
int cub[7];
vector <int> temp(5); 

//µø:1, º≠:2, ∫œ:3, ≥≤:4 
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void Rotate(int x, int y, int c){ // ¡÷ªÁ¿ß ±º∏Æ¥Ÿ¿Ω ¡¬«• √ ±‚»≠ 
	switch(c){
		case 1: // µø 
			temp[1] = cub[5]; temp[2] = cub[4]; temp[3] = cub[6]; temp[4] = cub[2];
			cub[4] = temp[1]; cub[6] = temp[2]; cub[2] = temp[3]; cub[5] = temp[4];
			break;
		case 2: // º≠ 
			temp[1] = cub[6]; temp[2] = cub[4]; temp[3] = cub[5]; temp[4] = cub[2];
			cub[4] = temp[1]; cub[5] = temp[2]; cub[2] = temp[3]; cub[6] = temp[4];
			break;
		case 3: // ∫œ 
			temp[1] = cub[3]; temp[2] = cub[4]; temp[3] = cub[1]; temp[4] = cub[2];
			cub[4] = temp[1]; cub[1] = temp[2]; cub[2] = temp[3]; cub[3] = temp[4];
			break;
		case 4: // ≥≤ 
			temp[1] = cub[1]; temp[2] = cub[4]; temp[3] = cub[3]; temp[4] = cub[2];
			cub[4] = temp[1]; cub[3] = temp[2]; cub[2] = temp[3]; cub[1] = temp[4];
			break;
	}
	temp.clear();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> x >> y >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) cin >> map[i][j];
	for(int i = 1; i <= k; i++) {
		cin >> c;
		int nx = x + dx[c];
		int ny = y + dy[c];
		//cout << nx << " " << ny << "\n";
		if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		x = nx;
		y = ny;
		Rotate(x, y, c);
		if(map[x][y] == 0) map[x][y] = cub[4];
		else {
			cub[4] = map[x][y];
			map[x][y] = 0;
		}
		cout << cub[2] << "\n";
	}
	
	
}
