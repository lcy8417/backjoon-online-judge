#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, cnt = 0;
	cin >> n;
	m = n;
	while(1){
		m = 10*(m%10) + ((m/10 + m%10)%10);
		cnt++;
		if(n == m) break;
	}
	cout << cnt;
}
