#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, res;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int height, room, guest;
		cin >> height >> room >> guest;
		int cnt = 0;
		for(int i = 1; i <= room; i++){
			int c = i;
			int f = 100;
			bool flag = false;
			for(int j = 1; j <= height; j++){
				res = (f * j) + c;
				cnt++;
				if(cnt == guest){
					cout << res << "\n";
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
	}
}
