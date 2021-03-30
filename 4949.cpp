#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string text;
	stack <char> s;
	while(1){
		getline(cin, text, '\n');
		if(text[0] == '.') break;
		bool flag = false;
		for(int i = 0; text[i] != '\0'; i++){ 
			if(text[i] == '(' || text[i] == '[' || text[i] == '{'){
				s.push(text[i]);
			}else if(text[i] == ')' || text[i] == ']' || text[i] == '}'){
				if(s.empty()){
					flag = true;
					cout << "no" << "\n";
					break;
				}else{
					char c = s.top();
					if(c == '(' && text[i] == ')'){
						s.pop();
					}else if(c == '[' && text[i] == ']'){
						s.pop();
					}else if(c == '{' && text[i] == '}'){
						s.pop();
					}else{
						cout << "no" << "\n";
						flag = true;
						break;
					}
				}
			}
		}
		if(!flag){
			if(!s.empty()) cout << "no" << "\n";
			else cout << "yes" << "\n";
		}
		while(!s.empty()) s.pop();
	}
}
