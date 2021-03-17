#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if(n % 4 == 0 && (n % 400 == 0 || n % 100 != 0)) cout << 1;
	else cout << 0;
}
