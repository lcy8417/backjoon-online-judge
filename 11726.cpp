#include <iostream>
using namespace std;

int dy[1001];

int go(int n){
	if(dy[n]) return dy[n];
	if(n == 1) return 1;
	if(n == 2) return 2;
	return dy[n] = go(n-1) % 10007 + go(n-2) % 10007;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	dy[1] = 1;
	dy[2] = 2;
	go(n);
	cout << dy[n] % 10007;
}
