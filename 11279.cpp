#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, x;
	cin >> N;
	priority_queue <int> q;
	for(int i = 1; i <= N; i++){
		cin >> x;
		if(x == 0 && q.empty()) cout << 0 << "\n";
		else if(x == 0) {
			cout << q.top() << "\n";
			q.pop();
		}
		else q.push(x);
	}
}
