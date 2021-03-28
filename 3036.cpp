#include <bits/stdc++.h>
using namespace std;

int arr[101];

int gdc(int a, int b){
	int c;
	while(b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(){
	ios::sync_with_stdio(false);
	int n, a, b;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		if(i >= 2){
			int x = gdc(arr[1], arr[i]);
			cout << arr[1] / x << "/" << arr[i] /x << "\n";
		}
	}
	
}	
