#include <iostream>

using namespace std;

int n, m, r, c, d, res;
int map[51][51];
bool ch[51][51];
// 0 : 북 | 1 : 동 | 2 : 남 | 3 : 서 

bool isCleaner(int x, int y){
	if((x-1<1||ch[x-1][y]||map[x-1][y])&&(x+1>n||ch[x+1][y]||map[x+1][y]) // 전부청소 됐거나 벽 일때 
		&&(y-1<1||ch[x][y-1]||map[x][y-1])&&(y+1>m||ch[x][y+1]||map[x][y+1])) return true;
		return false;	
}

int Rotation(int x){
	switch(x){
		case 0:
			return 3;
		case 1:
			return 0;
		case 2:
			return 1;
		case 3:
			return 2;
	}
}

void CleanPlace(int x, int y, int dir){
	switch(dir){
		case 0: // 북에서 서로 이동 
			if(y-1 > 0 && !map[x][y-1] && !ch[x][y-1]) c = y-1;
			d = Rotation(dir);
			break;
		case 1:
			if(x-1 > 0 && !map[x-1][y] && !ch[x-1][y]) r = x-1; 
			d = Rotation(dir);
			break;
		case 2:
			if(y+1 < m && !map[x][y+1] && !ch[x][y+1]) c = y+1;
			d = Rotation(dir);
			break;
		case 3:
			if(x+1 < n && !map[x+1][y] && !ch[x+1][y]) r = x+1;
			d = Rotation(dir);
			break;
	}
}



int main(){
	cin >> n >> m;
	cin >> r >> c >> d;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> map[i][j];
		}
	}
	r += 1;
	c += 1;
	while(1){
		if(!map[r][c] && !ch[r][c]){ // 현재위치청소 
			ch[r][c] = true;
			res++;
		}
		if(isCleaner(r, c)){
			bool flag = false;
			switch(d){ // 바라보는 방향 뒤쪽이 벽인지 확인 
				case 0: // 북  
					if(r+1 > n || map[r+1][c]) flag = true; 
					break;
				case 1: // 동 
					if(c-1 < 1 || map[r][c-1]) flag = true;
					break;
				case 2: // 남
					if(r-1 < 1 || map[r-1][c]) flag = true;
					break;
				case 3: // 서 
					if(c+1 > m || map[r][c+1]) flag = true;
					break;
			}
			if(flag) break;
			switch(d){ // 방향 뒤쪽이 벽이아니면 후진 
				case 0: // 북  
					r += 1; 
					break;
				case 1: // 동 
					c -= 1;
					break;
				case 2: // 남
					r -= 1;	
					break;
				case 3: // 서 
					c += 1;
					break;
			}
		}else CleanPlace(r, c, d);
	}
	cout << res;
}
