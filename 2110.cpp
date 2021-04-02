#include <bits/stdc++.h>

using namespace std;

long long unsigned int house[200001];
int N, C;

int wifi(int key){
	int cnt = 1;
	int cur = house[1];
	for(int i = 2; i <= N; i++){
		if(house[i] - cur >= key) {
			cnt++;
			cur = house[i];	
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	long long unsigned int lt, rt, res = 0;
	cin >> N >> C;
	for(int i = 1; i <= N; i++) cin >> house[i];
	sort(house+1, house+1+N);
	lt = 1;
	rt = house[N];
	while(lt <= rt){
		long long unsigned int key = (lt+rt) / 2;
		if(wifi(key) >= C){
			res = max(res, key);
			lt = key+1;
		}else rt = key-1;
	}
	cout << res;
}
