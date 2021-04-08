#include <iostream>

using namespace std;

bool des[10];
string N;
int M, a, ac = 0;

void DFS(int L, int value, int cnt){
	if(L > N.size()+1) return;
	if(L >= 1){
		ac = min(ac, abs(value-stoi(N)) + cnt); 
	}
	for(int i = 0; i <= 9; i++){
		if(!des[i]){
			DFS(L+1, value*10 + i, cnt+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	ac = abs(stoi(N)-100);

	for(int i = 0; i < M; i++){
		cin >> a;
		des[a] = true; // 사용 못함 
	}
	DFS(0, 0, 0);
	cout << ac;
	return 0;
}
