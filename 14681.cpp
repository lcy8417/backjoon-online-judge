#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int x, y;
	cin >> x >> y;
	if(x > 0 && y > 0) cout << 1;
	else if(x < 0 && y > 0) cout << 2;
	else if(x < 0 && y < 0) cout << 3;
	else cout << 4;
}
