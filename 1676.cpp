#include <bits/stdc++.h>

using namespace std;

stack <int> s5;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int temp = i;
		if(temp / 10 >= 1 && temp % 10 == 0){
			while(temp % 10 == 0){
				cnt++;
				temp /= 10;
			}
		}
		if(temp % 5 == 0) s5.push(temp);
	}
	while(!s5.empty()){
		int x = s5.top();
		s5.pop();
		while(x > 0 && x % 5 == 0){
			cnt++;
			x /= 5;
		}
	}
	cout << cnt;
}
