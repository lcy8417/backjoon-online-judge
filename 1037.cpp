#include <bits/stdc++.h>
using namespace std;

int arr[51];

int main(){
	ios_base::sync_with_stdio(false);
	int n, i = 1;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr+1, arr+1+n);
	cout << arr[1] * arr[n];
}
