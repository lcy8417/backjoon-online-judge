#include <bits/stdc++.h>

using namespace std;

int arr[100001];
char op[200001];
int main(){
	ios_base::sync_with_stdio(false);
	int n, p1 = 1, p2 = 1, m = 1;
	stack <int> s;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	while(m <= n){
		if(s.empty()) {
			s.push(m++);
			op[p1++] = '+';
			continue;
		}
		else{
			int x = s.top();
			if(x == arr[p2]){
				s.pop();
				p2++;
				op[p1++] = '-';
			}else {
				s.push(m++);
				op[p1++] = '+';
			}
		}
	}
	while(!s.empty()){
		int x = s.top();
		s.pop();
		if(x > arr[p2]){
			cout << "NO" << "\n";
			exit(0);
		}else {
			op[p1++] = '-';
			p2++;
		}
	}
	for(int i = 1; i < p1; i++) cout << op[i] << "\n";
}


