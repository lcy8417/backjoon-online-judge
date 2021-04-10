#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int T, M, N, x, y, res=1, p1=1, p2=1;
bool flag = false;
int GCD(int x, int y){
	if(x < y){
		int temp = x;
		x = y;
		y = temp;
	}
	while(y!=0){
		int r = x%y;
		x = y;
		y = r;
	}
	return x;
}

int LCM(int x, int y){
	return x * y / GCD(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> M >> N >> x >> y;
		int len = LCM(M, N);
		flag = false;
		res = 1;
		p1 = 1;
		p2 = 1;
		if(x-p1 == y-p2) {
			cout << x-p1+1 << "\n";
			continue;
		}
		while(1){
			if(M - p1 < N - p2){
				p2 += M-p1+1;
				res += M-p1+1;
				p1 = 1;
			}else{
				p1 += N-p2+1;
				res += N-p2+1;
				p2 = 1;
			}
			if(x-p1 == y-p2){
				res += x-p1;
				flag = true;
				break;
			}
			if(res > len) break;
		}
		if(flag) cout << res << "\n";
		else cout << -1 << "\n";
	}
}
