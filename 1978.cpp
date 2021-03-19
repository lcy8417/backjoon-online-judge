#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main() {
	ios_base::sync_with_stdio(false);
	int n, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = 1; i <= n; i++){
		if(arr[i] == 1) continue;
		bool flag = false;
		for(int j = 2; j < arr[i]; j++)
			if(arr[i] % j == 0) flag = true;
		if(!flag) cnt++;
	}
	cout << cnt;
}
