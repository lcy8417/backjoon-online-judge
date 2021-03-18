#include <bits/stdc++.h>
using namespace std;

char c[81];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> c;
		int cnt = 0;
		int sum = 0;
		for(int j = 0; c[j] != '\0'; j++){
			if(c[j] == 'O') sum += ++cnt;
			else if(c[j] == 'X') cnt = 0;
		}
		cout << sum << "\n";
	}
}
