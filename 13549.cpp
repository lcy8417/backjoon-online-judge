#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool check[200001];
int res = 2147000000;
int rep;

int main(){
	int n, k;
	queue <pair<int, int> > q;
	cin >> n >> k;
	q.push(make_pair(n, 0));
	while(!q.empty()){
		int x = q.front().first;
		int time = q.front().second;
		q.pop();
		if(x == k){
			res = min(time, res);
			continue;
		}
		if(x-1 >= 0 && !check[x-1]){
			check[x-1] = true;
			q.push(make_pair(x-1, time+1));	
		}
		if(x*2 <= 200000 && !check[x*2]){
			check[x*2] = true;
			q.push(make_pair(x*2, time));	
		}
		if(x+1 <= 200000 && !check[x+1]){
			check[x+1] = true;
			q.push(make_pair(x+1, time+1));
		}
	}
	cout << res;
}
