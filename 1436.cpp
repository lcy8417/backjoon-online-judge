#include <bits/stdc++.h>
using namespace std;

bool isTitle(int n){
	int cnt = 0;
	while(n > 0){
		if(n % 10 == 6) cnt++;
		else cnt = 0;
		if(cnt >= 3) return true;
		n /= 10;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, cnt = 0;
	cin >> n;
	for(int i = 666; ;i++){
		if(isTitle(i)) cnt++;
		if(cnt == n) {
			cout << i;
			break;
		}
	}
}
