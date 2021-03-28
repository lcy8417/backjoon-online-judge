#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, maxi = 1, mini = 1;
	cin >> n >> m;
	if(n < m){
		int temp = n;
		n = m;
		m = temp;
	}
	for(int i = 2; i <= n; i++) 
		if(n % i == 0 && m % i == 0) maxi = i;
	
	mini = maxi * (n/maxi) * (m/maxi);
	cout << maxi << "\n" << mini;
}
