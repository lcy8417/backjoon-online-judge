#include <bits/stdc++.h>
using namespace std;

int ch[26];

int main() {
	ios_base::sync_with_stdio(false);
	int n, cnt = 0;
	char key;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		bool flag = false;
		for(int j = 0; j < s.length(); j++){
			if(ch[s[j] - 'a'] == 1){
				flag = true;
				break;
			} 
			if(s[j] != s[j+1]) ch[s[j]-'a'] = 1;
		}
		for(int j = 0; j < 26; j++) ch[j] = 0;
		if(!flag) cnt++;
	}
	cout << cnt;
}
