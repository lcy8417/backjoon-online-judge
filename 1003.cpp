#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int> > dy(41, make_pair(0, 0));

void fib(int n){
	if(dy[n] != 0) return dy[n];
	if(n == 0) {
		dy[n].first = 1;
		return 0;
	}if(n == 1){
		dy[n].second = 1;
		return 1;
	}else{
	 	dy[n].first = fib(n-1) + fib(n-2);
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, a;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a;
		fib(a);
		//cout << dy[0] << " " << dy[1] << "\n";
		//dy[0] = 0; dy[1] = 0;
	}
}
