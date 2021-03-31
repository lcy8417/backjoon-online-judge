#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, p = 0, cnt = 1;
	queue <int> q;
	vector <int> ouput;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) q.push(i);
	while(!q.empty()){		
		if(cnt % k == 0){
			ouput.push_back(q.front());
			q.pop();
			cnt=1;
		}
		else{
			q.push(q.front());
			q.pop();
			cnt++;
		}
	}
	cout << "<";
	for(int i = 0; i < ouput.size(); i++) {
		cout << ouput[i];
		if(i == ouput.size() - 1) cout << ">";
		else cout << ", ";
	}
}
