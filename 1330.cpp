#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if(n < m) cout << "<";
	else if(n > m) cout << ">";
	else cout << "==";
}
