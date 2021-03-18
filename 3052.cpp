#include <bits/stdc++.h>
using namespace std;

int arr[11];
int cnt;

int main(){
	ios_base::sync_with_stdio(false);
	for(int i = 1; i <= 10; i++) {
		cin >> arr[i];
		arr[i] %= 42;
		bool flag = false;
		for(int j = i-1; j >= 1; j--){
			if(arr[i] == arr[j]) {
				flag = true;
				break;
			}
		}
		if(!flag) cnt++;
	}
	cout << cnt;
}
