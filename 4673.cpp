#include <bits/stdc++.h>
using namespace std;

int dy[10001];

void selfNum(){
	for(int i = 1; i <= 10000; i++){
		int sum = i;
		while(1){
			int temp = sum;
			while(temp > 0){
				sum += temp % 10;
				temp /= 10;
			}
			if(sum > 10000) break;
			dy[sum] = 1;
		}
	}
	for(int i = 1; i <= 10000; i++) {
		if(dy[i] == 0) cout << i << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	selfNum();
}
