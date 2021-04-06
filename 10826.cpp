#include <bits/stdc++.h>

using namespace std;

string dy[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	dy[0] = "0";
	dy[1] = "1";
	dy[2] = "1";
	for(int i = 3; i <= n; i++) {
		string temp = "";
		int upper = 0;
		int size = dy[i-1].length() - dy[i-2].length();
		for(int j = 1; j <= size; j++) temp += '0';
		temp += dy[i-2];
		dy[i-2] = temp;
		temp = "";
		for(int j = dy[i-1].length()-1; j >= 0; j--){ // 뒤에부터연산 
			int a = dy[i-1][j]-'0';
			int b = dy[i-2][j]-'0';
			temp += (char)((upper+a+b)%10+'0');
			if(upper+a+b >= 10) upper = 1;
			else upper = 0;
		}
		if(upper) dy[i] = "1";
		reverse(temp.begin(), temp.end());
		dy[i] += temp;
	}
	cout << dy[n];
	return 0;
}
