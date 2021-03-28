#include <bits/stdc++.h>
using namespace std;

int dy[100001];

struct Val{
	int w;
	int v;
	Val(int a, int b){
		w = a;
		v = b;
	}
};

int main(){
	ios::sync_with_stdio(false);
	int n, m, w, v, res = 0;
	cin >> n >> m;
	vector <Val> bag(n+1, Val(0, 0));
	for(int i = 1; i <= n; i++){
		cin >> w >> v;
		bag[i].w = w;
		bag[i].v = v;
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= bag[i].w; j--){
			dy[j] = max(dy[j], dy[j-bag[i].w] + bag[i].v);
			res = max(res, dy[j]);
		}
	}
	cout << res;
}	
