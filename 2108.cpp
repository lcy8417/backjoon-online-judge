#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> v1, pair<int ,int > v2){
	if(v1.second == v2.second){
		return v1.first < v2.first;
	}else return v1.second > v2.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, sum = 0, maxi = -4001, mini = 4001, cnt = 1, noun = 0, range = 0;
	cin >> n;
	vector <int> v(n);
	vector <pair<int, int> > dy;
	
	for(int i = 0; i < v.size(); i++){
		cin >> v[i];
		sum += v[i];
		maxi = max(maxi, v[i]);
		mini = min(mini, v[i]);
	}
	sort(v.begin(), v.end());
	range = maxi - mini;
	maxi = -4001;
	for(int i = 0; i < v.size(); i+= cnt){
		cnt = 1;
		for(int j = i+1; j < v.size(); j++){
			if(v[i] == v[j]) cnt++;
			else break;
		}
		dy.push_back(make_pair(v[i], cnt));
		
	}
	sort(dy.begin(), dy.end(), compare);
	
	if(dy[0].second == dy[1].second) noun = dy[1].first;
	else noun = dy[0].first;
	
	cout << round((double)sum / n) << "\n";
	cout << v[v.size() / 2] << "\n";
	cout << noun << "\n";
	cout << range << "\n";
}
