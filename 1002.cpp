#include <bits/stdc++.h>
using namespace std;

int x2, y2, r2, x3, y3, r3;

int main(){
	ios_base::sync_with_stdio(false);
	int n, cnt = 0, s = 9999, b = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x2 >> y2 >> r2 >> x3 >> y3 >> r3;
		cnt = 0;
		if(x2 == x3 && y2 == y3 && r2 == r3) cout << -1;
		else{
			// distance
			int dis = sqrt((x2- x3) * (x2- x3) + (y2- y3) * (y2- y3));
			s = min(r2, r3);
			b = max(r2, r3);
			if(dis - b <= s){ //in circle
				if(dis + s == b) cnt = 1;
				else if(dis + s > b) cnt = 2;
				else cnt = 0;
			}else{ // out circle
				if(dis < r2 + r3) cnt = 2;
				else if (dis > r2 + r3) cnt = 0;
				else if(dis == r2 + r3) cnt = 1;
			}	
		}
		cout << cnt << "\n";
	}
}
