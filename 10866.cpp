#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string text;
	queue <int> q;
	int n, m;
	cin >> n;
	while(n--){
		cin >> text;
		if(text == "push_back") {
			cin >> m;
			q.push(m);
		}else if(text == "push_front"){
			cin >> m;
			q.push(m);
			for(int i = 1; i <= q.size()-1; i++){
				q.push(q.front());
				q.pop();
			}
		}else if(text == "front"){
			if(q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}else if(text == "back"){
			if(q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}else if(text == "empty"){
			if(q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}else if(text == "pop_front"){
			if(q.empty()) cout << -1 << "\n";
			else{
				cout << q.front() << "\n";
				q.pop();
			}
		}else if(text == "pop_back"){
			if(q.empty()) cout << -1 << "\n";
			else{
				for(int i = 1; i <= q.size()-1; i++){
					q.push(q.front());
					q.pop();
				}
				cout << q.front() << "\n";
				q.pop();
			}
		}else if(text == "size"){
			cout << q.size() << "\n";
		}
	}
}
