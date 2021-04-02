#include <bits/stdc++.h>

using namespace std;

struct Hip{
	int x;
	Hip(int a){
		x = a;
	}
	bool operator<(const Hip &b) const{
		return x > b.x;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, x;
	cin >> N;
	priority_queue <Hip> q;
	for(int i = 1; i <= N; i++){
		cin >> x;
		if(x == 0 && q.empty()) cout << 0 << "\n";
		else if(x == 0) {
			cout << q.top().x << "\n";
			q.pop();
		}
		else q.push(Hip(x));
	}
}
