#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 100000

using namespace std;

int N, K, res;
int pos[200001];
queue <int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	q.push(N);
	pos[N] = 1;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		if(p == K){
			cout << pos[p]-1;
			break;
		}
		if(!pos[p*2] && p*2 <= MAX){
			pos[p*2] = pos[p] + 1;
			q.push(p*2);
		}
		if(!pos[p+1] && p+1 <= MAX){
			pos[p+1] = pos[p] + 1;
			q.push(p+1);
		}
		if(!pos[p-1] && p-1 >= 0){
			pos[p-1] = pos[p] + 1;
			q.push(p-1);
		}
	}
}
