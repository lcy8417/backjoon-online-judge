#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	stack <char> s;
	string t, res = "";
	cin >> n;
	while(n--){
		cin >> t;
		if(t[0] == ')'){
			cout << "NO" << "\n";
			continue;
		}
		for(int i = 0; i < t.length(); i++){
			if(t[i] == '(') s.push('(');
			if(t[i] == ')'){
				if(s.empty()){
					res = "NO";
					break;
				}else s.pop();
			}
		}
		if(res == ""){
			if(s.empty()){
				res = "YES";
			}else{
				res = "NO";
				while(!s.empty()) s.pop();
			}
		}
		cout << res << "\n";
		res = "";
	}
}
