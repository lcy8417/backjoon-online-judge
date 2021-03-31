#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	string text;
	queue <int> q;
	cin >> n;
	while(n--){
		cin >> text;
		if(text == "push"){
			cin >> m;
			q.push(m);
		}else if(text == "front"){
			if(q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}else if(text == "back"){
			if(q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}else if(text == "size"){
			cout << q.size() << "\n";
		}else if(text == "empty"){
			if(q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}else if(text == "pop"){
			if(q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
	}
}
