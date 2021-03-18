#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main(){
	ios_base::sync_with_stdio(false);
	int n, maxi = 0;
	double sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		maxi = max(maxi, arr[i]);
	}
	for(int i = 1; i <= n; i++){
		sum += ((double)arr[i] / maxi) * 100;
	}
	cout << sum / n;
}
