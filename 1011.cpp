#include <bits/stdc++.h>
using namespace std;

int res;

int main() {
	ios_base::sync_with_stdio(false);
	int n, s, e;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s >> e;
		long long last = e - s;
		long long maxi = 0;
		long long cur = 0;
		long long diff = 1;
		long long cnt = 0;
		while(cur + diff <= last){
			cur += diff;
			diff += 2;
			maxi++; 
		}
		last -= cur;
		cnt = maxi * 2 - 1;
		cnt += (long long)ceil((double)last / (double)maxi);
		cout << cnt << "\n";
	}
}
