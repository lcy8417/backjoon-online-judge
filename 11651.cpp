#include <bits/stdc++.h>
using namespace std;

struct Pos{
	int x;
	int y;
	Pos(int a, int b){
		x = a;
		y = b;
	}
	bool operator<(const Pos &b) const{
		if(y == b.y) return x < b.x;
		else return y < b.y;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <Pos> Point;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		Point.push_back(Pos(a, b));
	}
	sort(Point.begin(), Point.end());
	for(int i = 0; i < n; i++){
		cout << Point[i].x << " " << Point[i].y << "\n";
	}
}
