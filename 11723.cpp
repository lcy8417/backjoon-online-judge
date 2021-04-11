#include <bits/stdc++.h>

using namespace std;

map <int, int> m;
int N, num;
string com;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	while(N--){
		cin >> com;
		if(com == "add"){
			cin >> num;
			if(!m[num]) m[num] = 1;
		}else if(com == "check"){
			cin >> num;
			if(m[num]) cout << 1 << "\n";
			else cout << 0 << "\n";
		}else if(com == "remove"){
			cin >> num;
			if(m[num]) m[num] = 0;
		}else if(com == "toggle"){
			cin >> num;
			if(m[num]) m[num] = 0;
			else m[num] = 1;
		}else if(com == "all"){
			for(int i = 1; i <= 20; i++) m[i] = 1;
		}else if(com == "empty"){
			for(int i = 1; i <= 20; i++) m[i] = 0;
		}
	}
}
