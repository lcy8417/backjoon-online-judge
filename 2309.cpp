#include <bits/stdc++.h>

using namespace std;

int arr[9];
int res[7];
int ch[9];

void DFS(int s, int L, int sum){
	if(sum > 100 || L >= 8) return;
	if(sum == 100){
		for(int i = 0; i < 7; i++) cout << res[i] << " ";
		exit(0);
	}else{
		for(int i = s; i < 9; i++){
			if(ch[i] == 0){
				res[L] = arr[i];
				ch[i] = 1;
				DFS(i+1, L+1, sum+arr[i]);
				ch[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0; i < 9; i++) cin >> arr[i];
	sort(arr, arr+9);
	//for(int i = 0; i < 9; i++) cout << arr[i] << " ";
	DFS(0, 0, 0);
}
