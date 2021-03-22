#include <bits/stdc++.h>
using namespace std;

int x = 1;
int n;

void makeStar(int n){
	if(n == 0){
		cout << "*";
		return;
	}else{
		for(int i = 1; i <= x; i++){
			for(int j = 1; j <= x; j++){
				if(i >= x + 1 && i <= x/3 && j >= x + 1 && j <= x/3) {
					cout << " ";
				}
				else makeStar(n-1);
			}
			cout << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) x *= 3;
	makeStar(n);
}
