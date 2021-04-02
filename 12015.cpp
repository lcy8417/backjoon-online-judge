#include <bits/stdc++.h>

using namespace std;

vector <int> LIS;


int main(){
	ios_base::sync_with_stdio(false);
	int N, x, len = 0;
	cin >> N;
	LIS.push_back(0);
	for(int i = 1; i <= N; i++) {
		cin >> x;
		int cur = LIS[len];
		if(x > cur) {
			LIS.push_back(x);
			len++;
		}
		else{
			auto pos = lower_bound(LIS.begin()+1, LIS.end(), x);
			*pos = x;
		}
	}
	cout << len;
}
