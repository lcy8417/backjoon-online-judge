#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <pair<int, int> > w;
	vector <int> res(n, 1);
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		w.push_back(make_pair(a, b));
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			if(w[i].x < w[j].x && w[i].y < w[j].y) res[i]++;
		}
	}
	for(int i = 0; i < n; i++) cout << res[i] << " ";
}
