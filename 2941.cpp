#include <bits/stdc++.h>
using namespace std;

string cro[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	int cnt = 0, idx = 0;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		cnt++;
		if(i < s.length()-1){
			for(int j = 0; j < 8; j++){
				if(j == 2){
					if(cro[j][0] == s[i] && cro[j][1] == s[i+1] && cro[j][2] == s[i+2]){
						i+=2;
						break;
					}
				}
				else if(cro[j][0] == s[i] && cro[j][1] == s[i+1]){
					i++;
					break;
				}
			}
		}
	}
	cout << cnt;
}
