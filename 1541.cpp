#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	int sum = 0, ch = 0;
	string temp = "";
	cin >> s;
	for(int i = 0; i <= s.size(); i++){
		if(s[i] == '+' || s[i] == '-' || s[i] == '\0'){
			if(ch) sum -= stoi(temp);
			else sum += stoi(temp);
			if(s[i] == '-') ch = 1;
			temp = "";
			}else temp += s[i];
		
	}
	cout << sum << "\n";
	return 0;
}
