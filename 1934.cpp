#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, a, b, maxi = 1, mini = 1;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		if(a < b){
			int temp = a;
			a = b;
			b = temp;
		}
		for(int i = 2; i <= a; i++) 
			if(a % i == 0 && b % i == 0) maxi = i;
	
		mini = maxi * (a/maxi) * (b/maxi);
		cout << mini << "\n";
		maxi = 1;
		mini = 1;
	}
}
