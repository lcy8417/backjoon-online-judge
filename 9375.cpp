#include <bits/stdc++.h>

using namespace std;

int dy[101][101];
int n, m;
vector<pair<int, string> >cloth;

int main() {
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int res = 1;
		cin >> m;
		for(int j = 1; j <= m; j++){
			cin >> a >> b;
			int flag = 0;
			for(int k = 0; k < cloth.size(); k++){
				if(cloth[k].second == b){
					flag = 1;
					cloth[k].first++;
					break;
				}
			}
			if(!flag) cloth.push_back(make_pair(1, b));
		}
		for(int j = 0; j < cloth.size(); j++){
			res *= (cloth[j].first +1);
		}
		res -= 1;
		cout << res << "\n";
		cloth.clear();
	}
}
