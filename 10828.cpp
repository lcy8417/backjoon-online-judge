#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string t;
	stack <int> s;
	int n, m;
	cin >> n;
	while(n--){
		cin >> t;
		if(t == "push"){
			cin >> m;
			s.push(m);
		}else if(t == "top"){
			if(s.empty()) cout << -1 << "\n";
			else cout << s.top() << "\n";
		}else if(t == "size") {
			cout << s.size() << "\n";
		}else if(t == "empty"){
			if(s.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}else if(t == "pop"){
			if(s.empty()) cout << -1 << "\n";
			else{
				cout << s.top() << "\n";
				s.pop();
			}
		}
	}
}
