#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, n, i = 0;
	string p, st, temp = "";
	deque <int> q, rev;
	cin >> T;
	while(T--){
		cin >> p >> n >> st;
		bool flag = false;
		for(int i = 0; i < st[i] != '\0'; i++){
			if(st[i] == '[') continue;
			else if(st[i] >= '0' && st[i] <= '9'){
				temp += st[i];
			}
			else if(st[i] == ']' || st[i] == ','){
				if(temp == "") continue;
				q.push_back(stoi(temp));
				temp = "";
			}
		}
		for(int i = 0; i < p[i] != '\0'; i++){
			if(p[i] == 'R'){
				if(q.empty() || q.size() == 1) continue;
				while(!q.empty()){
					rev.push_back(q.back());
					q.pop_back();
				}
				while(!rev.empty()) {
					q.push_back(rev.front());
					rev.pop_front();
				}
			}else{
				if(q.empty()){
					cout << "error" << "\n";
					flag = true;
					break;
				}else q.pop_front();
			}
		}
		if(!flag){
			cout << "[";
			if(!q.empty()){
				cout << q.front();
				q.pop_front();
			}
			while(!q.empty()) {
				cout << "," << q.front();
				q.pop_front();
			}
			cout << "]" << "\n";
		}
		while(!q.empty()) q.pop_back();
		while(!rev.empty()) rev.pop_back();
	}
}
