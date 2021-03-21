#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int n;

int HanoiTop(int x){
	if(x == 1){
		return 1;
	}else{
		return 1 + HanoiTop(x-1)*2;
	}
}

void HanoiOrder(int x, int from, int by, int to){
	if(x == 1){
		cout << from << " " << to << "\n";
		return;
	}else{
		HanoiOrder(x-1, from, to, by);
		cout << from << " " << to << "\n";
		HanoiOrder(x-1, by, from, to);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	cout << HanoiTop(n) << "\n";
	HanoiOrder(n, 1, 2, 3);
}
