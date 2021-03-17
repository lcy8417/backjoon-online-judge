#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int A, B, C;
	cin >> A >> B >> C;
	cout << (A+B)%C << endl;
	cout << ((A%C) + (B%C))%C << endl;
	cout << (A * B)%C << endl;
	cout << ((A%C) * (B%C))%C << endl;
}
