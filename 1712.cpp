#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int A, B, C, sum = 0, cnt = 0;
	cin >> A >> B >> C;
	sum = A;
	if(B >= C){
		cout << -1;
		exit(0);
	}
	cnt = sum / (C-B) + 1;
	cout << cnt;
}
