#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int x, y, sum = 0, mul = 1;
	int arr[3];
	cin >> x >> y;
	for(int i = 0; i < 3; i++){
		arr[i] = x * (y % 10);
		y /= 10;
	}
	for(int i = 0; i < 3; i++){
		cout << arr[i] << endl;
		sum += arr[i] * mul;
		mul *= 10;
	}
	cout << sum;
}

