#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int x, y, w, h, dx, dy;
	cin >> x >> y >> w >> h;
	dx = min(x, abs(w-x));
	dy = min(y, abs(h-y));
	cout << min(dx, dy);
}
