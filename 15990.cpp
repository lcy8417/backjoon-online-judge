#include <iostream>
#define DIV 1000000009
using namespace std;

long long dy[100001][4];
bool visited[100001];

int main(){
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	int T, n;
	cin >> T;
	while(T--){
		long long res = 0;
		cin >> n;
		dy[1][1] = 1;
		dy[2][2] = 1;
		dy[3][3] = 1;
		if(!visited[n]){
			for(int i = 1; i <= n; i++){
				if(visited[i]) continue;
				for(int j = 1; j <= 3; j++){
					if(j == 1){
						dy[i+2][2] = (dy[i+2][2] + dy[i][j]) % DIV;
						dy[i+3][3] = (dy[i+3][3] + dy[i][j]) % DIV;
					}else if(j == 2){
						dy[i+1][1] = (dy[i+1][1] + dy[i][j]) % DIV;
						dy[i+3][3] = (dy[i+3][3] + dy[i][j]) % DIV;
					}else{
						dy[i+1][1] = (dy[i+1][1] + dy[i][j]) % DIV;
						dy[i+2][2] = (dy[i+2][2] + dy[i][j]) % DIV;
					}
				}
				visited[i] = true;
			}
		}
		res = dy[n][1] + dy[n][2] + dy[n][3];
		cout << res % DIV << "\n";
	}
}
