#include <bits/stdc++.h>
using namespace std;

int dy[10];

int main() {
	ios_base::sync_with_stdio(false);
	int a, b, c, sum = 0;
	cin >> a >> b >> c; 
	sum = a * b * c;
	while(sum > 0){
		dy[sum%10]++;
		sum/=10;
	}
	for(int i = 0; i < 10; i++) cout << dy[i] << "\n";
}
