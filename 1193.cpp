#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, i = 1, j = 1, cnt = 1;
	cin >> n;
	while(cnt < n){
		if(i == 1 && j == 1){
			cnt++;
			j++;
			if(cnt >= n) break;
		}
		else if((i+j) % 2 == 1){
			j--;
			i++;
			cnt++;
			if(cnt >= n) break;
			if(j == 1){
				i++;
				cnt++;
				if(cnt >= n) break;
			}
		}else if((i+j) % 2 == 0){
			j++;
			i--;
			cnt++;
			if(cnt >= n) break;
			if(i == 1){
				j++;
				cnt++;
				if(cnt >= n) break;
			}
		}
	} 
	cout << i << "/" << j;
}
