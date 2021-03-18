#include <vector>
#include <bits/stdc++.h>
using namespace std;

int n;

long long sum(std::vector<int> &a) {
	long long ans = 0;
    for(int i = 0; i < n; i++) ans += a[i];
	return ans;
}

int main(){
	cin >> n;
	vector <int> v;
	for(int i = 0; i < n; i++){
		int m;
		cin >> m;
		v.push_back(m);
	}
	cout << sum(v);
}
