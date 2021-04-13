#include <iostream>

using namespace std;

int dy[1001];
int go(int n){
	if(dy[n]) return dy[n];
	if(n == 1) return 1;
	if(n == 2) return 3;
	return dy[n] = go(n-1) % 10007 + (2*go(n-2)) % 10007;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	dy[1] = 1;
	dy[2] = 3;
	cin >> n;
	go(n);
	cout << dy[n]  % 10007;
}
