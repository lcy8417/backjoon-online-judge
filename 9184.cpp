#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int dy[51][51][51];

int w(int x, int y, int z){
	if(x <= 0 || y <= 0 || z <= 0) {
		return 1;
	}
	if(dy[x][y][z] != 0) return dy[x][y][z];
	else if(x > 20 || y > 20 || z > 20) {
		return dy[x][y][z] = w(20, 20, 20);
	}else if(x < y && y < z){
		return dy[x][y][z] = w(x, y, z-1) + w(x, y-1, z-1) - w(x, y-1, z);
	}else{
		return dy[x][y][z] = w(x-1, y, z) + w(x-1, y-1, z) + w(x-1, y, z-1) - w(x-1, y-1, z-1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int a, b, c;
	while(1){
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
}


