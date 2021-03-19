#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, i = 1, j = 1, cnt = 1;
	char focus;
	cin >> n;
	while(cnt != n){
		if(cnt == n) break;
		if(i == 1 && j ==1) {
			j++;
			focus = 'j';
			cnt++;
		}
		else if(j == 1){
			focus = 'i';
			cnt++;
			i++;
		}else if(i == 1){
			focus = 'j';
			cnt++;
			j++;
		}
		if(focus == 'i'){
			i--;
			j++;
			cnt++; 
		}else{
			i++;
			j--;
			cnt++; 
		}
	}
	cout << i << "/" << j;
}
