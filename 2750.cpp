#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);
	for(int i = 0; i < n; i++) cout << arr[i] << "\n";
}
