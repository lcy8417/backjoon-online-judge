#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++)
			cout << "*";
		cout << "\n";
	}
}