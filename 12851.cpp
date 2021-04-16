#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector <int> check(200001, 2147000000);
int res;
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
		if(res != 0 && time > res) continue; // 정답이 있는데 정답보다 시간이 클때 
		if(x == k){
			if(res == 0) {
				res = time;
				rep++;
			}
			else{
				if(res == time) rep++;	
			}
			continue;
		}
		if(x-1 >= 0 && check[x-1] >= time+1){
			check[x-1] = time+1;
			q.push(make_pair(x-1, time+1));	
		}
		if(x*2 <= 200000 && check[x*2] >= time+1){
			check[x*2] = time+1;
			q.push(make_pair(x*2, time+1));	
		}
		if(x+1 <= 200000 && check[x+1] >= time+1){
			check[x+1] = time+1;
			q.push(make_pair(x+1, time+1));
		}
	}
	cout << res << "\n" << rep;
}
