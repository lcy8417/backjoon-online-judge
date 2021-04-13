#include <iostream>

using namespace std;

int dy[1001];
int a[1001];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		dy[i] = a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i-1; j++){
			dy[i] = min(dy[i], dy[j] + a[i-j]);
		}
	}
	cout << dy[n];
}
