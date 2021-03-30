#include <bits/stdc++.h>

using namespace std;

long long int res; 
long long int m;

int main(){
	ios_base::sync_with_stdio(false);
	int n, r, temp;
	cin >> n >> r;
	if(n-r < r){ // n 이 25 보다 작을땐 
		if(r < 25) res += 
		for(int i = r+1; i <= n; i+=) {
			int temp = i;
			while(temp % 5 == 0){
				res++;
				temp /= 5;
			}
			while(temp % 2 == 0) {
				m++;
				temp /= 2;
			}
		}
		for(int i = 1; i <= n-r; i+=5){
			int temp = i;
			while(temp % 5 == 0){
				res--;
				temp /= 5;
			}
			while(temp % 2 == 0) {
				m--;
				temp /= 2;
			}
		}
	}
	else{
		for(int i = n-r+1; i <= n; i+=5) {
			int temp = i;
			while(temp % 5 == 0){
				res++;
				temp /= 5;
			}
			while(temp % 2 == 0) {
				m++;
				temp /= 2;
			}
		}
		for(int i = 1; i <= r; i+=5){
			int temp = i;
			while(temp % 5 == 0){
				res--;
				temp /= 5;
			}
			while(temp % 2 == 0) {
				m--;
				temp /= 2;
			}
		}
	}
	if(res > m) cout << m;
	else cout << res;
}
