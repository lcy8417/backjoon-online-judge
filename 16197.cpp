#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool visit[22][22][22][22]; 
bool isRes = false;
struct Coin{
	int fx;
	int fy;
	int sx;
	int sy;
	int cnt;
	Coin(int a, int b, int c, int d, int e){
		fx = a;
		fy = b;
		sx = c;
		sy = d;
		cnt = e;
	}
}; 

char map[21][21];
queue <Coin> q;
string s;
int res = 2147000000; 

//o: ����
//.: �� ĭ
//#: ��

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, fx=0, fy=0, sx=0, sy=0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			map[i][j+1] = s[j];
			if(s[j] == 'o'){
				if(!fx && !fy){
					fx = i;
					fy = j+1;
				}else{
					sx = i;
					sy = j+1;
				}
			}
		}
	}
	q.push(Coin(fx, fy, sx, sy, 0));
	visit[fx][fy][sx][sy] = true;
	while(!q.empty()){
		fx = q.front().fx;
		fy = q.front().fy;
		sx = q.front().sx;
		sy = q.front().sy;
		int cnt = q.front().cnt;
		q.pop();
		 // ���� �ΰ��� ��������  
		if ((fx < 1 || fy < 1 || fx > n || fy > m) || (sx < 1 || sy < 1 || sx > n || sy > m)){ // ���� �ϳ��� �������� 
			if(cnt <= 10){
				cout << cnt;	
				isRes = true;
			}
			break;
		}if(cnt > 10){ // 10������ ���� ������ �Ѵٸ� 
			break;
		}
		for(int i = 0; i < 4; i++){
			int nfx = fx+dx[i];
			int nfy = fy+dy[i];
			int nsx = sx+dx[i];
			int nsy = sy+dy[i];
			if((nfx < 1 || nfy < 1 || nfx > n || nfy > m) && (nsx < 1 || nsy < 1 || nsx > n || nsy > m)) continue; // �Ѵ� �������� ������ �� 
			if((map[nfx][nfy] == '#' && map[nsx][nsy] == '#')) continue; // �Ѵ� ���� �� 
			
			else if(map[nfx][nfy] == '#'){
				if(!visit[fx][fy][nsx][nsy]){
					visit[fx][fy][nsx][nsy] = true;
					q.push(Coin(fx, fy, nsx, nsy, cnt+1));
				}	
			}else if(map[nsx][nsy] == '#'){
				if(!visit[nfx][nfy][sx][sy]){
					visit[nfx][nfy][sx][sy] = true;
					q.push(Coin(nfx, nfy, sx, sy, cnt+1));
				}
			}else if(!visit[nfx][nfy][nsx][nsy]){
				visit[nfx][nfy][nsx][nsy] = true;
				q.push(Coin(nfx, nfy, nsx, nsy, cnt+1));
			}
		} 
	}
	if(!isRes) cout << -1;
}
