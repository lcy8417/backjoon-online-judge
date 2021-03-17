#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int h, m;
	cin >> h >> m;
	if(m >= 45) m -= 45;
	else{
		if(h == 0){
			h = 23;
		}else h -= 1;
		m += 15;
	}
	cout << h << " " << m;
}
