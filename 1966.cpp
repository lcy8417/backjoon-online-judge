#include <bits/stdc++.h>

using namespace std;

struct Text{
	int index;
	int import;
	Text(int a, int b){
		index = a;
		import = b;
	}

};
bool compare(int a, int b){
	return a > b;
}
int main(){
	ios_base::sync_with_stdio(false);
	int n, a, b, c, x, cnt = 0;
	cin >> n;
	queue <Text> q;
	vector <int> v;
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		cin >> a >> b;
		for(int j = 0; j < a; j++){
			cin >> c;
			q.push(Text(j, c));
			v.push_back(c);
		}
		sort(v.begin(), v.end(), compare);
		for(int j = 0; j < a; j++){
			while(v[j] != q.front().import){
				q.push(q.front());
				q.pop();
			}
			cnt++;
			if(q.front().index == b) break;
			q.pop();
		}
		cout << cnt << "\n";
		while(!q.empty()) q.pop();
		v.clear();
	}
}
