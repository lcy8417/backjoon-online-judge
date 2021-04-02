#include <bits/stdc++.h>

using namespace std;

long long unsigned int tree[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	int N, M;
	long long unsigned int lt, rt, H = 0;
	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> tree[i];
	sort(tree+1, tree+1+N);
	lt = 0;
	rt = tree[N];
	while(lt <= rt){
		long long unsigned int sum = 0;
		long long unsigned int key = (lt + rt) / 2;
		for(int i = 1; i <= N; i++){
			if(tree[i] > key) sum += (tree[i]-key);
		}
		if(sum >= M){
			H = max(key, H);
			lt = key+1;
		}else rt = key-1;
	}
	cout << H;
}
