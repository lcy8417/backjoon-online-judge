#include <bits/stdc++.h>

using namespace std;

int N;
int a[10001];


int main(){
	cin >> N;
	int flag = false;
	for(int i = 1; i <= N; i++) cin >> a[i];	
	for(int i = 2; i <= N; i++){
		if(a[i-1] < a[i]) {
			flag = true;
			break;
		}
	}
	if(!flag) cout << -1;
	else{
		for(int i = N-1; i >= 1; i--){
			if(a[i] < a[i+1]){
				for(int j = N; j >= i+1; j--){
					if(a[i] < a[j]) {
						swap(a[i], a[j]);
						break;
					}
				}
				for(int j = N; j > i+1; j--){
					for(int k = i+1; k <= j-1; k++){
						if(a[k] > a[j]) swap(a[k], a[j]);
					}
				}
				break;
			}
		}
		for(int i = 1; i <= N; i++) cout << a[i] << " ";
	}
}
