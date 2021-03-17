#include <bits/stdc++.h>
using namespace std;

int v[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	int n, cnt = 0, index = 0, maxi = -101;
	for(int i = 1; i <= 9; i++) cin >> v[i];
	for(int i = 1; i <= 9; i++){
		if(maxi < v[i]){
			maxi = v[i];
			index = i;
		}
	}
	cout << maxi << "\n" << index;
}
