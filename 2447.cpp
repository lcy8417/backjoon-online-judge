#include <bits/stdc++.h>
using namespace std;

char s[3001][3001];
int a = 1, b = 1, n, m;

void printStar(int x){
	if(x == 3){
		for(int i = a; i < a+3; i++){
			for(int j = b; j < b+3; j++){
				if(i % 3 == 2 && j % 3 == 2) s[i][j] = ' ';
				else s[i][j] = '*';
			}
		}
	}else{
		for(int i = 1; i <= 3; i++){
			for(int j = 1; j <= 3; j++){
				if(i == 2 && j == 2){
					for(int i = a; i < a+x/3; i++){
						for(int j = b; j < b+x/3; j++){
							s[i][j] = ' ';
						}
					}
				}else printStar(x / 3);
				b += x/3;
			}
			b -= x;
			a += x/3;
		}
		a -= x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	printStar(n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) cout << s[i][j];
		cout << "\n";
	}
}
