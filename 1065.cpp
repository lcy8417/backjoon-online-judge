#include <bits/stdc++.h>
using namespace std;

int dy[10001];

int hanNum(int n){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(i <= 99) cnt++;
		else{
			int temp = i;
			int f = temp / 100;
			int s = temp / 10 - f * 10;
			int t = temp - f*100 - s*10;
			if(f - s == s - t) cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << hanNum(n);
}
