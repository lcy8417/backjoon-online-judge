#include <iostream>
#define MIN -1000000001
#define MAX 1000000001
using namespace std;

int op[4]; // +, -, x, /
int n, minRes = MAX, maxRes = MIN;
int a[101];

void go(int x, int s, int sum){
	if(x == n){
		minRes = min(minRes, sum);
		maxRes = max(maxRes, sum);
	}else{
		for(int i = s; i <= n; i++){
			if(op[0]){
				op[0]--;
				go(x+1, i+1, sum+a[i]);
				op[0]++;
			}if(op[1]){
				op[1]--;
				go(x+1, i+1, sum-a[i]);
				op[1]++;
			}if(op[2]){
				op[2]--;
				go(x+1, i+1, sum*a[i]);
				op[2]++;
			}if(op[3]){
				op[3]--;
				go(x+1, i+1, sum/a[i]);
				op[3]++;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 0; i < 4; i++) cin >> op[i];
	go(1, 2, a[1]);
	cout << maxRes << "\n" << minRes;
}
