#include <bits/stdc++.h>

using namespace std;

long long unsigned int N, k;

int main(){
	ios_base::sync_with_stdio(false);
	long long unsigned int lt=1, rt, res = 0;
	cin >> N >> k;
	rt = k;
	while(lt <= rt){
		long long unsigned int key = (lt+rt)/2;
		long long unsigned int cnt = 0;
		for(long long unsigned int i = 1; i <= N; i++){
			cnt += min(N, key / i);
		}
		if(cnt >= k){
			res = min(res, key);
			rt = key-1;
		}else lt = key+1;
	}
	cout << res;
}
