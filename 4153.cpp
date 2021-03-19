#include <bits/stdc++.h>
using namespace std;

int arr[3];

int main() {
	ios_base::sync_with_stdio(false);
	int x, y, z;
	while(1){
		cin >> arr[0] >> arr[1] >> arr[2];
		if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;
		sort(arr, arr + 3);
		if(arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) cout << "right" << "\n";
		else cout << "wrong" << "\n";
	}
}
