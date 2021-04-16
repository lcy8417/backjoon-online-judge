#include <iostream>
#include <vector>
#define MAX_SIZE 501
using namespace std;

int N, M, R, op, t;
int arr[MAX_SIZE][MAX_SIZE];
vector <vector <int> > temp(MAX_SIZE, vector<int> (MAX_SIZE, 0));

void Func(int x){
	switch(x){
		case 1:
			for(int i = 1; i <= N/2; i++){
				for(int j = 1; j <= M; j++){
					int t = arr[i][j];
					arr[i][j] = arr[N-i+1][j];
					arr[N-i+1][j] = t;
				}	
			}
			break;		
		case 2:
			for(int i = 1; i <= N; i++){
				for(int j = 1; j <= M/2; j++){
					int t = arr[i][j];
					arr[i][j] = arr[i][M-j+1];
					arr[i][M-j+1] = t;
				}
			}
			break;
		case 3:
			t = N;
			N = M;
			M = t;
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= M; j++)
					temp[i][j] = arr[M+1-j][i];
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= M; j++)
					arr[i][j] = temp[i][j];
			temp.clear();
			break;
	
		case 4:
			t = N;
			N = M;
			M = t;
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= M; j++)
					temp[i][j] = arr[j][N+1-i];
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= M; j++)
					arr[i][j] = temp[i][j];
			temp.clear();
			break;
		
		case 5:
			for(int i = 1; i <= N/2; i++){
				for(int j = 1; j <= M/2; j++){
					temp[i][j+M/2] = arr[i][j];
					temp[i+N/2][j+M/2] = arr[i][j+M/2];
					temp[i+N/2][j] = arr[i+N/2][j+M/2];
					temp[i][j] = arr[i+N/2][j];
				}
			}
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= M; j++)
					arr[i][j] = temp[i][j];
			temp.clear();
			break;
		case 6:
			for(int i = 1; i <= N/2; i++){
				for(int j = 1; j <= M/2; j++){
					temp[i+N/2][j] = arr[i][j]; // 1 > 4
					temp[i+N/2][j+M/2] = arr[i+N/2][j]; // 4 > 3
					temp[i][j+M/2] = arr[i+N/2][j+M/2]; // 3 > 2
					temp[i][j] = arr[i][j+M/2]; // 2 > 1
				}
			}
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= M; j++)
					arr[i][j] = temp[i][j];
			temp.clear();
			break;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> R;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> arr[i][j];
		}
	}	
	while(R--){
		cin >> op;
		Func(op);
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
