#include <bits/stdc++.h>

using namespace std;

int k;
char a[10];
long long maxi;
long long mini = 99999999999;
string maxRes;
string minRes;
bool visited[10];
void DFS(int L, int n, string sum){
	if(L == k+1){
		if(stoll(sum) > maxi){
			maxi = stoll(sum);
			maxRes = sum;
		}if(stoll(sum) < mini){
			mini = stoll(sum);
			minRes = sum;
		}
	}else{
		for(int i = 0; i <= 9; i++){
			if(!visited[i]){
				visited[i] = true;
				if(a[L] == '<'){
					if(n < i) DFS(L+1, i, sum + to_string(i));
				}else{
					if(n > i) DFS(L+1, i, sum + to_string(i));
				}	
				visited[i] = false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> k;
	for(int i = 1; i <= k; i++) cin >> a[i];
	for(int i = 0; i <= 9; i++){
		visited[i] = true;
		DFS(1, i, to_string(i));
		visited[i] = false;
	}
	cout << maxRes << "\n" << minRes;
}
