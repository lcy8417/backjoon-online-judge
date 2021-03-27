#include <bits/stdc++.h>
using namespace std;

struct Line{
	int x;
	int y;
	Line(int a, int b){
		x = a;
		y = b;
	}
	bool operator<(const Line &r) const{
		return x < r.x;
	}
};

int main(){
	ios::sync_with_stdio(false);
	int n, a, b, res = 1;
	cin >> n;
	vector <int> dy(501, 1);
	vector <Line> v(101, Line(0, 0));
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		v[i].x = a;
		v[i].y = b;
	}
	sort(v.begin() + 1, v.begin() + n + 1);
	for(int i = 1; i <= n-1; i++){
		int y = v[i].y;
		for(int j = i+1; j <= n; j++){
			int yy = v[j].y;
			if(y < yy) dy[j] = max(dy[j], dy[i]+1);
			res = max(res, dy[j]);
		}
	}
	cout << n - res;
}
