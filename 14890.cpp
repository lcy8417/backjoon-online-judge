#include <iostream>

using namespace std;

int a[101][101];
bool ch[101][101];
int res, N, L;;

bool Row(int x){ // 행 기준 
	for(int i = 1; i < N;){
		if(a[x][i]-1 == a[x][i+1]){ // 다음위치가 낮을 때 
			if(ch[x][i+1]) return false;
				ch[x][i+1] = true;
			for(int j = i+1; j < i + L; j++) {
				if(j+1 > N || a[x][j] != a[x][j+1] || ch[x][j+1]) return false;
				ch[x][j+1] = true;
			}
			i+=L; 
		}else if(a[x][i]+1 == a[x][i+1]) {// 다음 위치가 높을 때
			if(ch[x][i]) return false;
			ch[x][i] = true; 
			for(int j = i; j > i-L+1 ; j--) {
				if(j-1 < 1 || a[x][j] != a[x][j-1] || ch[x][j-1]) return false;
				ch[x][j-1] = true;
			}
			i++;
		}else if(a[x][i] == a[x][i+1])i++; // 같을 때는 그냥 올려줌 
		else return false;
	}
	return true; 
}

bool Col(int x){ // 열 기준 
	for(int i = 1; i < N;){
		if(a[i][x] -1 == a[i+1][x]){ // 다음위치가 낮을 때 
			if(ch[i+1][x]) return false;
			ch[i+1][x] = true;
			for(int j = i+1; j < i + L; j++) {
				if(j+1 > N || a[j][x] != a[j+1][x] || ch[j+1][x]) return false;
				ch[j+1][x] = true;
			}
			i+=L; 
		}else if(a[i][x]+1 == a[i+1][x]) {// 다음 위치가 높을 때 
			if(ch[i][x]) return false;
			ch[i][x] = true;
			for(int j = i; j > i-L+1 ; j--){
				if(j-1 < 1 || a[j][x] != a[j-1][x] || ch[j-1][x]) return false;		
				ch[j-1][x] = true;
			}
			i++;
		}else if(a[i][x] == a[i+1][x]) {
			i++; // 같을 때는 그냥 올려줌 
		}
		else  {
			return false;
		} 
	}
	return true; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> L;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++) cin >> a[i][j];
	for(int i = 1; i <= N; i++){
		if(Col(i)) res++;	
		for(int j = 1; j <= N; j++) for(int k = 1; k <= N; k++) ch[j][k] = false;
		if(Row(i)) res++;
		for(int j = 1; j <= N; j++) for(int k = 1; k <= N; k++) ch[j][k] = false;
	}
	cout << res;
}
