#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, res = 0;
	stack <int> s;
	cin >> n;
	while(n--) {
		cin >> m;
		if(!s.empty() && m == 0) s.pop();
		else s.push(m);
	}
	while(!s.empty()){
		res += s.top();
		s.pop();
	}
	cout << res;
}
