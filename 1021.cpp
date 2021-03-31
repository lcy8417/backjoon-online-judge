#include <bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, cnt = 0,index = 0;
	queue <int> q;
	cin >> n >> m;
	vector <int> v(m+1);
	for(int i = 1; i <= n; i++) q.push(i);
	for(int i = 1; i <= m; i++) cin >> v[i];
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= q.size(); j++){
			if(q.front() == v[i]) index = j;
			q.push(q.front());
			q.pop();
		}
		while(1){
			if(q.front() == v[i]){
				q.pop();
				break;
			}
			if(q.size() / 2 + 1 >= index){
				q.push(q.front());
				q.pop();
			}else{
				for(int k = 1; k <= q.size()-1; k++){
					q.push(q.front());
					q.pop();
				}
			}
			cnt++;
		}
	}
	cout << cnt;
}
